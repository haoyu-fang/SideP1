# C++ 撮合引擎（簡化版 Order Matching Engine）

## 📌 專案簡介
本專案為一個使用 C++ 實作的 **簡化版金融撮合引擎**，模擬交易所核心撮合邏輯，
重點在於 **價格優先、時間優先（Price-Time Priority）** 的實作，以及資料結構與系統設計的選擇。

此專案主要用於展示：
- C++ 系統設計能力
- 金融交易系統基本概念
- 對效能與時間複雜度的考量

---

## 🏗 系統架構設計

Order
├── orderId // 訂單編號
├── price // 價格
├── quantity // 數量
├── side // BUY / SELL
└── timestamp // 下單時間

OrderBook
├── bidBook // 買單簿（價格由高到低）
└── askBook // 賣單簿（價格由低到高）

MatchingEngine
├── addOrder()
├── match()
└── generateTrade()

Trade
├── buyOrderId
├── sellOrderId
├── price
└── quantity


---

## ⚙ 核心功能
- 限價單（Limit Order）
- 市價單（Market Order）
- 價格優先、時間優先撮合
- 支援部分成交與完全成交
- 成交紀錄（Trade Log）

---

## 🧠 設計決策說明

### 為什麼使用 `std::map<price, queue<Order>>`？
- `std::map` 自動維持價格排序
- 插入與查找時間複雜度為 **O(log N)**
- 非常適合實作價格優先的撮合邏輯

### 為什麼每個價格使用 `queue`？
- 同價位訂單依照先來先成交（FIFO）
- 符合真實交易所的時間優先規則

---

## ⏱ 時間複雜度分析
| 操作 | 時間複雜度 |
|----|----------|
| 新增訂單 | O(log N) |
| 移除訂單 | O(log N) |
| 撮合成交 | O(log N) |

---

## 🚀 執行方式
```bash
g++ -std=c++17 main.cpp -o matching_engine
./matching_engine



---

# 📗 Java README（中文）

# Java 小型銀行系統（Mini Banking System）

## 📌 專案簡介
本專案為一個使用 Java 撰寫的 **簡化銀行系統**，
重點在於 **物件導向設計（OOP）**、商業邏輯建模，以及交易安全性。

此專案展示：
- Java OOP 設計能力
- 後端系統的基礎架構概念
- 交易流程與例外處理

---

## 🏗 系統架構設計

User
├── userId
└── name

Account
├── accountId
├── balance
└── owner (User)

Transaction
├── transactionId
├── type (DEPOSIT / WITHDRAW / TRANSFER)
├── amount
└── timestamp

BankService
├── deposit()
├── withdraw()
└── transfer()


---

## ⚙ 核心功能
- 帳戶建立
- 存款 / 提款
- 帳戶間轉帳
- 交易紀錄查詢
- 基本輸入驗證與錯誤處理

---

## 🧠 設計決策說明

### 為什麼使用 Service Layer？
- 將商業邏輯與資料模型分離
- 提升可維護性與擴充性
- 符合實際後端系統設計方式

### Thread Safety 設計
- 轉帳流程使用 `synchronized`
- 避免多執行緒同時修改帳戶餘額
- 確保資料一致性

---

## ⚠ 例外處理
使用自訂 Exception 處理以下情境：
- 餘額不足
- 帳戶不存在
- 非法交易金額

---

## 🚀 執行方式
```bash
javac Main.java
java Main
