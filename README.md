2048 Multi-Mode Game on STM32F429 Discovery

Mô tả dự án

Dự án hiện thực trò chơi 2048 trên STM32F429 Discovery sử dụng thư viện TouchGFX, bao gồm 3 chế độ chơi:

Classic Mode: gộp các số giống nhau (2 + 2 = 4).

Letter Mode: gộp chữ cái (A + A = B, ..., K).

Super Merging Mode: gộp nhiều ô giống nhau liên tiếp (2-2-2 → 6).

🛠 Công cụ phát triển

Tool	            Version	        Mục đích

STM32CubeMX	      6.x.x	          Cấu hình Clock, GPIO, Middleware

STM32CubeIDE	    1.18.1         	IDE biên dịch mã cho STM32F429

TouchGFX Designer	4.25	          Thiết kế giao diện đồ họa

ST-Link Utility	  Mới nhất	      Flash firmware vào board

GCC ARM Embedded	Tích hợp sẵn	  Trình biên dịch trong STM32CubeIDE

FreeRTOS:         v10.6.1 (CMSIS-RTOS V2)

Git:              v2.30+

⚙ Hướng dẫn cài đặt & build

Bước 1: Cài đặt Tool
Cài đặt STM32CubeIDE: https://www.st.com/en/development-tools/stm32cubeide.html

Cài đặt TouchGFX Designer: https://www.st.com/en/development-tools/touchgfx.html

Clone repository: git clone https://github.com/DangZz07/STM32F429ZIT6_Game2048.git

Bước 2: Mở Project

Mở STM32CubeIDE.

Chọn File > Import > Existing Project into Workspace.

Chọn thư mục chứa project.

Bước 3: Build & Flash

Click Build Project (Ctrl + B).

Kết nối STM32F429 Discovery qua USB.

Nhấn Run > Debug để nạp chương trình.

