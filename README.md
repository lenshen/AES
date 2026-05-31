# AES-128 CBC Implementation in C++

這是一個從零開始（From Scratch）、無依賴任何外部套件的純 C++ AES-128 加解密演算法實作。本專案不僅實作了 AES 核心的區塊加密邏輯，更擴充支援了 **CBC 模式 (Cipher Block Chaining)** 與 **PKCS#7 填充 (Padding)**，能夠安全地處理任意長度的字串加密。

## ✨ 專案特色 (Features)

* **純 C++ 實作 (Zero Dependencies)**：不依賴 OpenSSL 或其他密碼學函式庫，完全以底層陣列與位元運算 (Bitwise Operations) 打造。
* **AES-128 核心**：完整包含 SubBytes、ShiftRows、MixColumns (基於 $GF(2^8)$ 有限體乘法) 以及 AddRoundKey 與 KeyExpansion。
* **CBC 模式支援**：實作了密碼區塊鏈接模式，透過初始化向量 (IV) 與前一區塊密文的 XOR 運算，解決 ECB 模式的安全性缺陷。
* **動態長度支援 (PKCS#7 Padding)**：自動計算並補齊字串長度至 16 Bytes 的倍數，並在解密後完美拔除填充物，還原原始明文。

## 📂 檔案結構 (File Structure)

* `aes.h`：標頭檔，封裝了對外開放的 API（金鑰擴展、CBC 加密、CBC 解密），隱藏底層細節。
* `aes.cpp`：核心實作檔，包含 S-Box、矩陣轉換、有限體數學運算以及加密鏈條邏輯。
* `main.cpp`：互動式主程式，提供使用者在終端機輸入任意字串進行加解密測試。

## 🚀 如何編譯與執行 (Build & Run)

請確保你的環境中已安裝 `g++` (GCC 編譯器)。

1. **編譯專案**：
   在終端機中輸入以下指令，將 `main.cpp` 與 `aes.cpp` 編譯成執行檔 `aes_tool`。
   ```bash
   g++ main.cpp aes.cpp -o aes_tool
