package AlarmClock;

import java.applet.Applet;

import java.applet.AudioClip;

import java.awt.Container;

import java.awt.GridLayout;

import java.awt.event.ActionEvent;

import java.awt.event.ActionListener;

import java.io.File;

import java.net.MalformedURLException;

import java.text.SimpleDateFormat;

import java.util.Date;

import javax.swing.*;

public class AlarmClock2 extends JFrame implements Runnable {
	
 JLabel ri ,shi, fen, miao, dangqian;

 JButton queding, dakai;

 JTextField music,RI, SHI, FEN, MIAO;

 int h=0,f=0,m=0,r=0;
 
 boolean fo=false;
 
 public AudioClip soumd1;
 
 public AlarmClock2() {
	 
     Container c = getContentPane();
     
     c.setLayout(new GridLayout(3, 1));
     
     JPanel jp = new JPanel();
     
     dangqian = new JLabel();
     
     jp.add(dangqian);
     
     c.add(jp);
     
     JPanel jp1 = new JPanel();
     
     music = new JTextField(21);
     
     dakai = new JButton("选择闹铃声");
     
     jp1.add(music);
     
     jp1.add(dakai);
     
     c.add(jp1);
     
     RI = new JTextField(4);
     
     ri = new JLabel("日");
     
     SHI = new JTextField(4);
     
     shi = new JLabel("时");
     
     FEN = new JTextField(4);
              
     fen = new JLabel("分");
     
     MIAO = new JTextField(4);
              
     miao = new JLabel("秒");
              
     JPanel jp2 = new JPanel();
     
     jp2.add(RI);
     
     jp2.add(ri);
     
     jp2.add(SHI);
     
     jp2.add(shi);
     
     jp2.add(FEN);
     
     jp2.add(fen);
     
     jp2.add(MIAO);
     
     jp2.add(miao);
               
     queding = new JButton("确定");
     
     jp2.add(queding);
     
     c.add(jp2);
     
     setSize(400, 200);
     
     setVisible(true);
     
     dakai.addActionListener(new ActionListener() {
    	 
	     public void actionPerformed(ActionEvent event) {
	    	 
	        JFileChooser fileChooser = new JFileChooser(); // 实例化文件选择器
	        
	        fileChooser.setFileSelectionMode(JFileChooser.FILES_AND_DIRECTORIES); // 设置文件选择模式,此处为文件和目录均可
	        
	        fileChooser.setCurrentDirectory(new File(".")); // 设置文件选择器当前目录
	        
	        fileChooser.setFileFilter(new javax.swing.filechooser.FileFilter() {
	        	
	            public boolean accept(File file) { // 可接受的文件类型
	            	
	                String name = file.getName().toLowerCase();
	                
	                return name.endsWith(".wav") || name.endsWith(".au") || name.endsWith(".mp3") || file.isDirectory();
	                
	            }
	
	            public String getDescription() { // 文件描述
	            	
	                return "音乐文件(*.wav,*.au,*.mp3)";
	                
	            }
	      });
	      if (fileChooser.showOpenDialog(AlarmClock2.this) == JFileChooser.APPROVE_OPTION) { // 弹出文件选择器,并判断是否点击了打开按钮
	    	  
	         String fileName = fileChooser.getSelectedFile().getAbsolutePath(); // 得到选择文件或目录的绝对路径
	         
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
	    
	         if(1<=r && r<=31 && 0<=h && h<=23 && 0<=f && f<=59 && 0<=m && m<=59)  	
	         {
	    	
	             fo=true;
	     
	         }
	         else
	    	
	             JOptionPane.showMessageDialog(null, "输入的时间错误");
	    
	     }catch(Exception e){
	    	 
	            JOptionPane.showMessageDialog(null, "请输入正确的时间");
	     
	     }
    
    }else{
    	
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
	 
     AlarmClock2 s = new AlarmClock2();
  
     Thread t1 = new Thread(s);
  
     t1.start();
  
     s.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
  
 }

 @SuppressWarnings("deprecation")
public void run() {
	 
     while (true) {
	  
         Date now = new Date();
   
         dangqian.setText("当前时间为: " + now.toString());
   
         if(fo)
         {
	   
             RI.setEditable(false);
    
             SHI.setEditable(false);
    
             FEN.setEditable(false);
    
             MIAO.setEditable(false);
    
             queding.setText("关闭");
    
             SimpleDateFormat ri=new SimpleDateFormat("dd");  //封装  为了获取日期
    
             SimpleDateFormat shi=new SimpleDateFormat("kk");  //封装 为了获取小时
    
             SimpleDateFormat fen=new SimpleDateFormat("mm");  //封装 为了获取分钟
    
             SimpleDateFormat miao=new SimpleDateFormat("ss");  //封装 为了获取秒钟
    
             int riqi=Integer.parseInt(ri.format(now));        //获取日期
    
             int shizhong=Integer.parseInt(shi.format(now));   //获取小时
    
             int fenzhong=Integer.parseInt(fen.format(now));  //获取分钟
    
             int miaozhong=Integer.parseInt(miao.format(now));  //获取秒钟
    
             if(riqi==r && shizhong==h && fenzhong==f && miaozhong==m) //判断条件
    	
             {
                 try {
        	 
                     soumd1=Applet.newAudioClip(new File(music.getText()).toURL()); //播放音乐
             
                     soumd1.loop();  //循环播放
             
                     fo=false;
             
                 } catch (MalformedURLException e) {
        	 
                       e.printStackTrace();
             
                   }
             }
        }
        try {
	   
            Thread.sleep(1000);
       
        } catch (InterruptedException ie) {
	   
          }
     }
  }
}