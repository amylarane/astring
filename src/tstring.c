#include<string.h>
#include<stdlib.h>

#include<tstring.h>

#ifdef NULL
#undef NULL
#define NULL '\0'
#endif

enum TStringVariant {
	STRAIGHT,
	REFERENCE
};

struct tstring {
	unsigned short length;
	char* value;
};

void string_cstring_copyterm(char* to, char* from, int length){
	memcpy(to, from, length);
	to[length] = (char)NULL;
}

String string_alloc(int length){
	String str = malloc(sizeof(struct tstring));
	str->value = malloc(sizeof(char) * (length+1));
	str->length = length;
	return str;
}

String string_from_cstring(char* cstring){
	int length = strlen(cstring);

	String str = string_alloc(length);
	str->length = length;

	string_cstring_copyterm(str->value, cstring, length);

	return str;
}

String string_from_array(char* value, int length){
	String str = string_alloc(length);
	str->length = length;
	string_cstring_copyterm(value, str->value, length);
	return str;
}

const char* const string_cstring(String string){
	if(string){
		return string->value;
	}

	return NULL;
}

const unsigned short string_length(String string){
	if(string){
		return string->length;
	}
	return NULL;
}

char string_index(String string, int index){
	if(string && index < string->length)
		return string->value[index];
	return NULL;
}

String string_clone(String string){
	if(!string) return 0;

	String str = string_alloc(string->length);
	str->length = string->length;
	string_cstring_copyterm(string->value, str->value, string->length);
	return str;
}

String string_substring(String string, int index, int length){
	if(!string || (index + length) > string->length)
		return 0;


	String str = string_alloc(length);
	str->length = length;
	string_cstring_copyterm(str->value, string->value+index, length);
	return str;
}

String string_delete(String string){
	if(string){
		free(string->value);
		free(string);
	}
	return 0;
}

