//Log 的作用是将消息和状态打印到工作台。
//有三种功能：warning、error、trace。

#include <iostream>

using namespace std;

class Log
{
public:
    enum Level
    {
        LevelError=0,LevelWarning,LevelInfo
    };
private:
    int m_LogLevel = LevelInfo;//默认设置为所有的东西都应该打印到控制台上。
public:
    void SetLevel(int level)
    {
        m_LogLevel = level;
    }

    void Warn(const char* message)//这里的const char* 的意思其实就是字符串。
    {
        if(m_LogLevel >= LevelWarning)
        {
            cout<<"[Warning]:"<<message<<endl;
        } 
    }
    void Error(const char* message)//这里的const char* 的意思其实就是字符串。
    {
        if(m_LogLevel >= LevelError)
        {
            cout<<"[Error]:"<<message<<endl;
        } 
    }
    void Info(const char* message)//这里的const char* 的意思其实就是字符串。
    {
        if(m_LogLevel >= LevelInfo)
        {
            cout<<"[Information]:"<<message<<endl;
        } 
    }
};

int main()
{
    Log log;//创建了一个变量。
    /*
    log.SetLevel(2);
    cout<<log.m_LogLevel<<endl;//这里如果 m_LogLevel 仍然是私有的，就打印不出来，改为 public 就可以打印了。
    */
    
    log.SetLevel(log.LevelWarning);//warning:1.   error:0.   trace:2
    //这时候其实操作台上就只会打印出 Warn 和 Errer，因为初始设置为了Warning。
    log.Warn("Hello!");
    log.Info("sad!");
    log.Error("good");
    return 0;
}