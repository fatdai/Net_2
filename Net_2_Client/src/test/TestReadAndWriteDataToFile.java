package test;

import java.io.BufferedOutputStream;
import java.io.DataOutputStream;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.util.concurrent.TimeUnit;

import proto.Msguser.msguser;
import proto.Msguser.msguser.Builder;
import server.entity.User;

public class TestReadAndWriteDataToFile {
	
	// 测试将一个username password 写到文件里面去,然后读出来
	static void write(String filepath,byte[] bytes){
		
		try {
			DataOutputStream dop = new DataOutputStream(new BufferedOutputStream(new FileOutputStream(filepath)));
			dop.write(bytes);
			dop.flush();
			dop.close();
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		} catch (IOException e) {
			e.printStackTrace();
		}	
	}
	
	static User readUser(String filepath){
		try {
			msguser u = msguser.parseFrom(new FileInputStream(filepath));
			User user = new User();
			user.setUsername(u.getUsername());
			user.setPassord(u.getPassword());
			return user;
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		} catch (IOException e) {
			e.printStackTrace();
		}
		return null;
	}
	
	
	public static void main(String[] args) {
		
		Builder b = msguser.newBuilder();
		b.setUsername("zhangsan");
		b.setPassword("123456");
		msguser u = b.build();
		
		write("data/"+u.getUsername(), u.toByteArray());
		
		try {
			TimeUnit.MILLISECONDS.sleep(1000);
		} catch (InterruptedException e) {
			e.printStackTrace();
		}
		
		User ret = readUser("data/"+u.getUsername());
		if (null != ret) {
			System.out.println("username:" + ret.getUsername());
			System.out.println("password:" + ret.getPassord());
		}
	}
	
}
