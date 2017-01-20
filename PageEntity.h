#ifndef PageEntity_H
#define PageEntity_H 1

#define DEFAULT_REFERENCE_BIT true
#define DEFAULT_MODIFY_BIT false

class PageEntity {
public:
	PageEntity(long long __page) : _page(__page),
		_reference_bit(DEFAULT_REFERENCE_BIT), _modify_bit(DEFAULT_MODIFY_BIT) {}
	long long page();
	int reference_bit();
	int modify_bit();

	void set_reference_bit();
	void set_modify_bit();
	void reset_reference_bit();
	void reset_modify_bit();
protected:
	long long _page;
	bool _reference_bit;
	bool _modify_bit;
};

#endif