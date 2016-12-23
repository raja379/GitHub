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
							tf.setText(new String(buf));
							Thread.sleep(100);
						}
					}catch(Exception e){
						System.out.println(e);
				}
			}
			};
			setVisible(true);
			setTitle("Practice Frame");
			setLayout(null);
			setSize(1000,1000);
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
					tf.setText("");
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