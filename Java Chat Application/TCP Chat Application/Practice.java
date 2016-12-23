import java.awt.*;
import java.awt.event.*;
import java.util.*;
import java.io.*;
import java.net.*;

public class Practice extends Frame implements ActionListener{
	static Socket s;
	static ServerSocket ss;
	static Scanner in;
	static DataInputStream dis;
	static DataOutputStream dos;
	TextField tf;
	Button snd;	
	Thread t;
	public Practice(){
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
			}};
			setVisible(true);
			setTitle("Practice Frame");
			setLayout(null);
			setSize(1000,1000);
			tf = new TextField();
			snd = new Button("SEND");
			add(tf);
			add(snd);
			tf.setBounds(100,100,100,100);
			snd.setBounds(0,0,100,100);
			snd.addActionListener(this);
			ss = new ServerSocket(1234);
			s = ss.accept();
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
		Practice p = new Practice();
	}
}