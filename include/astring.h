#ifndef __ASTRING_H
#define __ASTRING_H

typedef struct astring* String;
String string_from_cstring(char* cstring);
String string_from_array(char* array, int length);

const char* const string_cstring(String str);
const unsigned short string_length(String str);

char string_index(String string, int index);

String string_substring(String string, int index, int length);
String string_copy(String string);
String string_delete(String string);

#endif //ASTRING_H
