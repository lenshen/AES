#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include "aes.h"

using namespace std;

void test() {
    // 預設 16 bytes 金鑰
    unsigned char key[16] = {0x2b, 0x7e, 0x15, 0x16, 0x28, 0xae, 0xd2, 0xa6, 
                             0xab, 0xf7, 0x15, 0x88, 0x09, 0xcf, 0x4f, 0x3c};
                             
    string s;
    cout << "請輸入要加密的字串 (不限長度): ";
    getline(cin, s);
    
    cout << "\n AES-128 CBC 加解密系統 " << endl;
    
    // 1. 金鑰擴展 
    KeyExpansion(key);
    
    // 2. 加密
    vector<unsigned char> cipher = encrypt_CBC(s);
    
    cout << "decode cipher size: " << cipher.size() << " bytes" << endl;
    cout << "Cipher : \n";
    for(int i = 0; i < cipher.size(); i++) {
        cout << hex << setw(2) << setfill('0') << (int)cipher[i] << " ";
        if ((i + 1) % 16 == 0) cout << endl; // 每 16 個 bytes 換行
    }
    cout << dec << endl; // 轉回 10 進位
    
    // 3. 解密
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    string decrypted_text = decrypt_CBC(cipher);
    
    cout << " decrypted_plaintext: " << decrypted_text << endl;
    
}

int main() {
    test();
    return 0;
}