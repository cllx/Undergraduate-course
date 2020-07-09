package AlarmClock;
import java.awt.*; 

import java.awt.event.*; 

import javax.swing.*; 

import java.applet.Applet; 

import java.applet.AudioClip; 

import java.io.File; 

import java.net.*; 

import java.text.SimpleDateFormat; 

import java.util.Date; 

public class AlarmClock extends JFrame implements Runnable { 

	JLabel dangqian; 

    JButton queding, xuanze; 

    JTextField music,RI, SHI, FEN, MIAO; 

    int h=0,f=0,m=0,r=0; 
     
    boolean fo=false; 

    public AudioClip soumd1; 

    public AlarmClock() { 
 
    	Container c = getContentPane(); 
 
    	c.setLayout(new  GridLayout(3, 1)); 

    	JPanel jp = new JPanel(); 

    	dangqian = new JLabel(); 

    	jp.add(dangqian); 

    	c.add(jp);

    	JPanel jp1 = new JPanel(); 

    	music = new JTextField(20); 

    	xuanze = new JButton("选择闹铃音乐"); 

    	jp1.add(music); 

    	jp1.add(xuanze); 

    	c.add(jp1); 

    	RI = new JTextField(4); 

    	SHI = new JTextField(4); 

    	FEN = new JTextField(4); 

    	MIAO = new JTextField(4); 
 
    	JPanel jp2 = new JPanel(); 
 
    	jp2.add(new JLabel("日")); 

    	jp2.add(RI); 

    	jp2.add(new JLabel("时")); 

    	jp2.add(SHI); 

    	jp2.add(new JLabel("分")); 

    	jp2.add(FEN); 

    	jp2.add(new JLabel("秒")); 

    	jp2.add(MIAO); 

    	queding = new JButton("确定"); 

    	jp2.add(queding); 

    	c.add(jp2); 

    	setSize(420, 150); 

    	setVisible(true); 

    	xuanze.addActionListener(new  ActionListener() { 

    		public void actionPerformed(ActionEvent event) { 

    			JFileChooser fileChooser = new JFileChooser();

    			fileChooser.setFileSelectionMode(JFileChooser.FILES_AND_DIRECTORIES); 

    			fileChooser.setCurrentDirectory(new File(".")); 

    			if(fileChooser.showOpenDialog(AlarmClock.this) == JFileChooser.APPROVE_OPTION) { 

    				String fileName = fileChooser.getSelectedFile().getAbsolutePath(); 

    				music.setText(fileName); 

    			} 

    		} 

    	}); 

    	queding.addActionListener(new ActionListener() { 

    		public void actionPerformed(ActionEvent event) { 

    			if(queding.getText().equals("确定")){ 

    				try{ 

    					r=Integer.parseInt(RI.getText()); 

    					h=Integer.parseInt(SHI.getText()); 

    					f=Integer.parseInt(FEN.getText()); 

    					m=Integer.parseInt(MIAO.getText()); 

    					if(1<=r && r<=31 && 0<=h && h<=23 && 0<=f && f<=59 && 0<=m && m<=59){ 

    						fo=true; 

    					} 

    					else

    						JOptionPane.showMessageDialog(null, "输入时间错误"); 

    				} 

    				catch(Exception e){ 

    					JOptionPane.showMessageDialog(null, "请输入正确的时间"); 

    				} 

    			} 

    			else{ 

    				fo=false; 

    				RI.setEditable(true); 

    				SHI.setEditable(true); 

    				FEN.setEditable(true); 

    				MIAO.setEditable(true); 

    				queding.setText("确定"); 

    				soumd1.stop(); 

    			} 

    		} 

    	}); 

    } 

    public static void main(String agrs[]) { 

    	AlarmClock s = new AlarmClock(); 

    	Thread t1 = new Thread(s); 

    	t1.start(); 

    	s.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE); 

    } 

    @SuppressWarnings("deprecation")
	public void run() { 
 
    	while(true) { 

    		Date now = Date(); 

    		dangqian.setText("当前时间: " + now.toString()); 

    		if(fo){ 

    			RI.setEditable(false); 

    			SHI.setEditable(false); 

    			FEN.setEditable(false); 

    			MIAO.setEditable(false); 

    			queding.setText("关闭"); 

    			SimpleDateFormat ri=new SimpleDateFormat("dd"); 

    			SimpleDateFormat shi= new SimpleDateFormat("kk"); 

    			SimpleDateFormat fen= new SimpleDateFormat("mm"); 

    			SimpleDateFormat miao= new SimpleDateFormat("ss"); 

    			int riqi=Integer.parseInt(ri.format(now)); 

    			int shizhong=Integer.parseInt(shi.format(now)); 

    			int fenzhong=Integer.parseInt(fen.format(now)); 

    			int miaozhong=Integer.parseInt(miao.format(now)); 

    			if(riqi==r && shizhong==h && fenzhong==f && miaozhong==m){ 

    				try{ 

    					soumd1=Applet.newAudioClip(new File(music.getText()).toURL()); 

    					soumd1.loop(); 

    					fo=false; 

    				} 

    				catch(MalformedURLException e){ 

    					e.printStackTrace(); 

    				} 

    			} 

    		} 

    		try{ 

    			Thread.sleep(1000); 

    		} 

    		catch(InterruptedException ie) { 

    		} 

    	} 

    }

	private Date Date() {
		// TODO Auto-generated method stub
		return null;
	} 

} 
