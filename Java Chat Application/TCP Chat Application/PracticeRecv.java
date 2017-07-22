import java.awt.*;
import java.awt.event.*;
import java.util.*;
import java.io.*;
import java.net.*;

public class PracticeRecv extends Frame implements ActionListener{
	static Socket s;
	static Scanner in;
	static DataInputStream dis;
	static DataOutputStream dos;
	TextField tf;
	Thread t;
	Button snd;
	PracticeRecv(){
		try{
			t = new Thread(){
				public void run(){
					try{
						while(s.isConnected()){
							byte[] buf = new byte[100];	
							dis.read(buf);
							String temp = VigenereCipher.decrypt(new String(buf),"ABCD");
							System.out.println("Decrypted Text: "+temp);
							tf.setText(temp);
							Thread.sleep(100);
						}
					}catch(Exception e){
						System.out.println(e);
				}
			}
			};
			setVisible(true);
			setTitle("Practice Frame");
			setLayout(new GridLayout());
			setSize(200,200);
			tf = new TextField();
			snd = new Button("SEND");
			snd.addActionListener(this);
			add(tf);
			add(snd);
			tf.setBounds(100,100,100,100);
			snd.setBounds(0,0,100,100);
			s = new Socket("LocalHost",1234);
			in = new Scanner(System.in);
			dis = new DataInputStream(s.getInputStream());
			dos = new DataOutputStream(s.getOutputStream());
			t.start();		
		}catch(Exception e){
			System.out.println(e);
		}
	}
	public void actionPerformed(ActionEvent ae){
		try{
			String comm = ae.getActionCommand();
			if(comm.equals("SEND")){
				String text = tf.getText();
				if(text.length() > 0){
					tf.setText("Message Sent successfully!!!");
					text = VigenereCipher.encrypt(text,"ABCD");
					System.out.println("Encrypted Text: "+text);
					dos.write(text.getBytes());
				}
			}
		}catch(Exception e){
			System.out.println(e);
		}
	}
	public static void main(String args[]){
		PracticeRecv p = new PracticeRecv();
	}
}