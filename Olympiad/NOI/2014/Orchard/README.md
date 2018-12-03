**National Olympiad in Informatics (Singapore) 2014 Problem 1**

Chúng ta có thể giải 3 subtasks đầu bằng DP:
  
  1. Gọi dp[i][1] là chi phí tối ưu nếu vị trí i là biên phải phần vườn của Bert, dp[i][0] là chi phí phải trả nếu đang xét đến từ vị trí      1 đến vị trí i mà chưa đi qua phần vườn nào của Bert.
  
  2. Ta có công thức như sau:
    
    dp[i][0] = dp[i - 1][0] + (a[i] == 1); 
    
    dp[i][1] = min(dp[i - 1][1] + (a[i] == 0), dp[i - 1][0] + (a[i] == 1));
    
    Kết quả sẽ là ans = min(ans, dp[i][1] + suff[i + 1]); (với suff[i] tương tư mảng dp[i][0] mà là đoạn [i, n]).
  
Cách giải subtask cuối có ý tưởng tương tự:
  
  1. Giới hạn biên trên và biên dưới phần vườn của Bert, rồi áp dụng công thức dp như 3 subtasks đầu + tính tổng số số 1 trong 1 đoạn.
  2. Kết quả của biên trên U và biên dưới D sẽ là max(dp[i][1] + tổng số số 1 của các phần không thuộc phần vườn Bert), với mọi i thuộc        [1, m].
  
*Time complexity: O(N * N * M).*

*Tags: #dp.*
