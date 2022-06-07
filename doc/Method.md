# 各種函數
## 關於 File.c method
### PathExists()
#### 函數原形:
int PathExists(const char* path)
#### 範例:
PathExists("TEST.txt");  
檢查檔案是否存在

### DirectoryExists()
#### 函數原形:
int DirectoryExists(const char* path)
#### 範例:
DirectoryExists("headers");  
檢查資料夾是否存在

### GetType()
#### 函數原形:
void GetType(const char* filename,char* result)
#### 範例:
GetType("TEST.txt",&test2[0]);  
查看屬性

### CreateDir()
#### 函數原形:
int CreateDir(const char* dir)
#### 範例:
CreateDir("TEST");  
建立新的資料夾，權限為777，但是最後還是要看umask值

### Delete()
#### 函數原形:
int Delete(const char* filename)
#### 範例:
Delete("TEST");  
可以刪除文件或是資料夾