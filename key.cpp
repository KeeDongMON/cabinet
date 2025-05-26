#include "key.h"


// _kbhit()= 어떤 버튼이라도 눌려졌나요? Were any buttons pressed?
bool any_key_pressed() {
    bool result = false;
    result = _kbhit();
    return result;
}

uint8_t get_key() {
    uint8_t result = 0;
    result = _getch();
    return result;
}

uint16_t get_key_code() {
    key_t key{ 0 }; //이렇게 하면 첫번쨰 멤버변수가 0으로 초기화된다고함.
    while (!any_key_pressed()) {
		// 아무 키도 눌리지 않았을 때는 계속 기다린다.
//printf("아무 키도 눌리지 않았습니다. \n");
    }

    //if (any_key_pressed()) {
    key.bound.lower = get_key();
    if ((key.bound.lower == EXT_CODE_1) || (key.bound.lower == EXT_CODE_2)) {
        key.bound.upper = get_key();
    }
    else {
        key.bound.upper = key.bound.lower;
        key.bound.lower = 0; // 이렇게 해도 되고
        //key.all >>= 8; // 이렇게 해도 된다.
        //key.bound.upper >> 8;
    }
    //}
    //return key.all; // 이렇게 하게 되면 return type을 key_t로 해야 하는데 
    // 받는 함수에서 영 불편하다.
    return key.all; // 그냥 uint16_t를 돌려주는게 받는 쪽에서 편하다.
}