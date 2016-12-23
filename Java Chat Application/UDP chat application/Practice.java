import java.awt.*;
import java.awt.event.*;
import java.util.*;
import java.io.*;
import java.net.*;

public class Practice extends Frame implements ActionListener{
	DatagramSocket s,ds;
	DatagramPacket dp;
	TextField tf;
	Button snd;	
	Thread t;
	public Practice(){
		try{
			t = new Thread(){
				public void run(){
					try{
						while(true){
							byte[] buf = new byte[1024];
							dp = new DatagramPacket(buf,1024);
							s.receive(dp);	
							String str = new String(dp.getData(),0,dp.getLength());
							tf.setText(str);
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
			s = new DatagramSocket(3000);
			t.start();
		}catch(BindException be){
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
				InetAddress ia = InetAddress.getByName("127.0.0.1");
				if(text.length() > 0){
					tf.setText("");
					dp = new DatagramPacket(text.getBytes(),text.length(),ia,4000);
					s.send(dp);
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