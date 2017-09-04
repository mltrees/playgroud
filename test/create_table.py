#!/usr/bin/python2.7
# coding: utf-8
#

# -*- coding: UTF-8 -*-
#安装 MYSQL DB for python
import MySQLdb as mdb
con = None
try:
  #连接 mysql 的方法： connect('ip','user','password','dbname')
  con = mdb.connect('localhost', 'root','123456');
  #所有的查询，都在连接 con 的一个模块 cursor 上面运行的
  cur = con.cursor()
 
  #创建一个表
  cur.execute("CREATE TABLE IF NOT EXISTS Writers(Id INT PRIMARY KEY AUTO_INCREMENT, Name VARCHAR(25))")
  cur.execute("INSERT INTO Writers(Name) VALUES('Jack London')")
  cur.execute("INSERT INTO Writers(Name) VALUES('Honore de Balzac')")
  cur.execute("INSERT INTO Writers(Name) VALUES('Lion Feuchtwanger')")
  cur.execute("INSERT INTO Writers(Name) VALUES('Emile Zola')")
  cur.execute("INSERT INTO Writers(Name) VALUES('Truman Capote')") 
   
finally:
  if con:
    #无论如何，连接记得关闭
    con.close()
