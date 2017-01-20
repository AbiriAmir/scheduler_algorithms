#include "PageEntity.h"

long long PageEntity::page() { return _page; }
int PageEntity::reference_bit() { return _reference_bit; }
int PageEntity::modify_bit() { return _modify_bit; }

void PageEntity::set_reference_bit() { _reference_bit = true; }
void PageEntity::set_modify_bit() { _modify_bit = true; }
void PageEntity::reset_reference_bit() { _reference_bit = false; }
void PageEntity::reset_modify_bit() { _modify_bit = false; }