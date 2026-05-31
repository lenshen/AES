#ifndef aes_H
#define aes_H

#include <vector>
#include <string>

using namespace std;

void KeyExpansion(unsigned char* init_key);


vector<unsigned char> encrypt_CBC(string s);


string decrypt_CBC(vector<unsigned char> cipher_result);

#endif