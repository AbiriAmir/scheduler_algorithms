#ifndef MEMORY_REFERENCE_H
#define MEMORY_REFERENCE_H 1

class MemoryReference {
public:
	enum AccessType {
		READ,
		WRITE
	};

	long long address;
	int bytes;
	AccessType accessType;

	MemoryReference(long long _address, int _bytes, AccessType accessType);
};

#endif