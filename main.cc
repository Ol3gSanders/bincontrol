#include <iostream>

using namespace std;

uint8_t setBit( uint8_t val, unsigned pos ); // установить бит на определенной позиции (0 -> 1)
uint8_t clearBit( uint8_t val, unsigned pos ); // сбросить бит на определенной позиции (1 -> 0)
bool isSetBit( uint8_t val, unsigned pos ); // узнать бит на определенной позиции, вводимой пользователем
void cout_hex_uint8( uint8_t val );

int main()
{
	uint8_t val = 0xFF;
	unsigned pos = 8;

	cout << std::hex << "0x" << +val << endl;
	cout << "clear bit at pos " << pos << endl;
	val = clearBit( val, pos );
	cout << std::hex << "0x" << +val << endl;
	if( isSetBit( val, pos ) ){
		cout << "bit is set at pos " << pos << endl;
	}
	else{
		cout << "bit is cleared at pos " << pos << endl;
	}

	val = setBit( val, pos );
	cout << "set bit at pos " << pos << endl;
	cout << std::hex << "0x" << +val << endl;
	if( isSetBit( val, pos ) ){
		cout << "bit is set at pos " << pos << endl;
	}
	else{
		cout << "bit is cleared at pos " << pos << endl;
	}

	return 0;
}

void cout_hex_uint8( uint8_t val )
{
	cout << std::hex << "0x" << +val << endl;
}

uint8_t setBit( uint8_t val, unsigned pos )
{
	uint8_t mask = 1 << ( pos - 1 );
	uint8_t ret_val = val | mask;

	return ret_val;
}

uint8_t clearBit( uint8_t val, unsigned pos )
{
	uint8_t mask = 1 << ( pos - 1 );
	uint8_t ret_val = ( val & ( ~mask ) );

	return ret_val;
}

bool isSetBit( uint8_t val, unsigned pos )
{
	bool is_set = false;
	uint8_t ret_val = ( val >> ( pos - 1 ) );
	if ( ret_val & 0x1 ){
		is_set = true;
	}

	return is_set;
}
