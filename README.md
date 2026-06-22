# quiz-app
**Hoàn thành tất cả các chức năng**
**Phải sử dụng ít nhất một container STL để lưu trữ dữ liệu (ví dụ: List, Set, Vector, Map, Dictionary, Stack, Queue, v.v.)**
**Thiết kế bài học và ứng dụng các khái niệm đã học trong chương 2, 3, 4, 5, 6.**

**Duy **
Xử lý dữ liệu
Branch làm việc: feature/data-loader
File phụ trách: data_loader.h, data_loader.cpp

Nhiệm vụ cụ thể:
Đọc file.
Thiết kế lớp Question chứa đầy đủ chính xác dữ liệu của số câu hỏi.( dùng vector )
Dòng nào là câu hỏi, dòng nào chứa danh sách đáp án, và bóc tách ký tự (a, b, c...) làm đáp án đúng.

**Hân  **
Thiết kế Giao diện cốt lõi 
Branch làm việc: feature/ui-display
File phụ trách: ui_display.h, ui_display.cpp

Nhiệm vụ cụ thể:
Tạo Class Candidate để lưu thông tin người thi (Tên, MSSV, lớp) và input để thí sinh nhập vào.
Thiết kế lớp UIDisplay: In tổng số câu hỏi, thông tin thí sinh, nội dung câu hỏi và danh sách đáp án dạng (a, b, c, d, e) ra màn hình, nhận phím điều hướng/đáp án từ người dùng.
(Thêm tính năng 1): Viết thêm hàm Pop-up hỏi thí sinh: Bạn có chắc chắn muốn nộp bài không?.

**Huy  **
Quản lý câu trả lời
Branch làm việc: feature/answer-manager
File phụ trách: answer_manager.h, answer_manager.cpp

Nhiệm vụ cụ thể:
Thiết kế lớp AnswerManager để lưu trữ cặp dữ liệu cấu trúc: Số thứ tự câu hỏi và Câu trả lời của thí sinh (cho phép ghi đè, sửa lại đáp án).
Xử lý logic trạng thái bỏ qua.
Nhặt ra danh sách số thứ tự các câu bị thí sinh bỏ trống và đưa ra cảnh báo trước khi nộp bài.

**Tâm **
Tính toán kết quả
Branch làm việc: feature/result-calculator
File phụ trách: result_calculator.h, result_calculator.cpp

Nhiệm vụ cụ thể:
Viết bộ đếm thời gian.
viết hàm tính điểm dựa trên việc đối chiếu danh sách câu trả lời thí sinh chọn với danh sách đáp án đúng từ file gốc.
viết hàm in ra bảng tổng kết chi tiết sau khi thi xong: điểm trên thang điểm 10, Số câu đúng, Thời gian làm bài, hỏi có muốn xem lại bài không.


**Khôi **
Branch làm việc: main
File phụ trách: main.cpp

Nhiệm vụ cụ thể:
Viết luồng xử lý chính trong main.cpp để khởi tạo các lớp.
Kiểm tra, duyệt và gộp bài (Merge) từ các branch
