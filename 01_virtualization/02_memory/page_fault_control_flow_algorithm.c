VPN = (VirtualAddress & VPN_MASK) >> SHIFT;
(Success, TlbEntry) = TLB_Lookup(VPN);
if (Success == True) {	// TLB Hit
	if (CanAccess(TlbEntry.ProtextBits) == True) {
		Offset = VirtualAddress & OFFSET_MASK;
		PhysAddr = (TlbEntry.PFN << SHIFT) | Offset;
		Register = AccessMemory(PhysAddr);
	}
	else
		RaiseException(PROTECTION_FAULT);
}
else {	// TLB Miss
	PTEAddr = PTBR + (VPN * sizeof(PTE));
	PTE = AccessMemory(PTEAddr);
	if (PTE.Valid == False)
		RaiseException(SEGMENTATION_FAULT);
	else {
		if (CanAccess(PTE.ProtextBits) == False)
			RaiseException(PROTECTION_FAULT);
		else if (PTE.Present == True) {
			// assuming hardware-managed TLB
			TLB_Insert(VPN, PTE.PFN, PTE.ProtectBits);
			RetryInstruction();
		}
		else if (PTE.Present == False)
			RaiseException(PAGE_FAULT);
	}
}
