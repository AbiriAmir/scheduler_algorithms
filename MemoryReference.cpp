#include "MemoryReference.h"

MemoryReference::MemoryReference(long long _address, int _bytes, AccessType _accessType) {
	address = _address;
	bytes = _bytes;
	accessType = _accessType;
}