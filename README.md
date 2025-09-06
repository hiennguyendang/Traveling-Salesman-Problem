# Travelling Salesman Problem (TSP) Solver

![C++](https://img.shields.io/badge/language-C++-blue.svg)
![Algorithm](https://img.shields.io/badge/algorithm-DP%20%2B%20Bitmasking-green.svg)
![Status](https://img.shields.io/badge/status-completed-success.svg)

## 📌 Giới thiệu
Đây là bài tập lớn môn **Cấu trúc rời rạc** (Trường Đại học Bách khoa – ĐHQG TP.HCM).  
Đề tài tập trung vào việc cài đặt và giải quyết **Bài toán Người đi bán hàng** (Travelling Salesman Problem - TSP) bằng cách kết hợp **Dynamic Programming (DP)** và **Bitmasking**.

- **Ngôn ngữ:** C++  
- **Sinh viên thực hiện:** Nguyễn Đăng Hiên – MSSV: 2310926  
- **Thời gian:** 06/2024  

## 🚀 Ý tưởng và phương pháp
- **Dynamic Programming (DP):** chia nhỏ bài toán thành các bài toán con và lưu kết quả trung gian để giảm tính toán lặp lại.  
- **Bitmasking:** dùng bit để biểu diễn tập các thành phố đã đi qua, giúp quản lý trạng thái hiệu quả.  

Công thức đệ quy tổng quát:
g(i, S) = min( C(i,k) + g(k, S - {k}) ) với k ∈ S
- `i`: đỉnh hiện tại  
- `S`: tập các đỉnh còn lại cần đi  
- `C(i,k)`: chi phí đi từ i đến k  

## 📂 Cấu trúc mã nguồn
- `tsm.h` : Khai báo lớp `TravelingSalesman` và các phương thức hỗ trợ.  
- `tsm.cpp` : Hiện thực chi tiết các phương thức.  

Các thành phần chính:
- `recursiveCalculate(pos, mask)`: hàm đệ quy chính tính chi phí tối ưu.  
- `TravelingOutString()`: sinh chuỗi lộ trình tối ưu.  
- Sử dụng mảng `valueCity` và `nextCity` để lưu chi phí và lộ trình.  

## ⚡ Độ phức tạp
- Độ phức tạp thời gian: **O(n² × 2ⁿ)**  
- Tốt hơn so với brute force **O(n!)**, cho phép giải quyết TSP ở quy mô vừa.  

## 🖥️ Cách chạy chương trình
1. Biên dịch:
   ```bash
   g++ tsm.cpp -o tsm
  ./tsm

