import java.awt.*;

import javax.swing.*;

import java.awt.event.*;
import java.util.*;
import java.applet.*;
import java.io.File;
import java.net.MalformedURLException;
import java.net.URI;
import java.net.URL;

public class Time extends JPanel implements Runnable,AudioClip{
	JTextField[] time=new JTextField[3];//�����趨����������
	JComboBox box;//����ѡ��
	String[] songs={"1.wav","2.wav","3.wav"};//���������б�
    JLabel lab1,lab2,lab6,lab7,lab8;//�����趨����������
    JButton b1=new JButton(),b2=new JButton();//��ť
    JPanel[] p=new JPanel[2];//�ڶ��е�����
   Clock c;//����һ��clock��ı���c�����Ի�ȡ���������q���䵱ʱ����ʾ����
   Icon icon=new ImageIcon("button1.png");//��ťͼ��
	Icon icon1=new ImageIcon("button2.png");
	int h,mi,s,count=0,count1=0; //count��count1Ϊ���Ʊ�����֮�����߳���ʹ��
	boolean flag=false,flag2=false;//���ı������߳���ʹ��
	String[] t=new String[3];//���ڴ洢�����趨ʱ��
	Calendar cal;//��ȡʱ��ı���
	//һ������Ϊ���ֲ�����ʹ�õı��� 
	File musicfile;
	 URI uri;
	 URL url;
	 AudioClip clip;
	 String song="1.wav";//Ĭ�ϳ�ʼ����
	 Background back=new Background();//����ͼ
	public Time(Clock clock) throws MalformedURLException
	{
		
		back.setBounds(0,0,410,410);//������С�趨		
		c=clock;//��c�������н�����clock���������
		for(int i=0;i<3;i++)
		{
			time[i]=new JTextField(4);
			time[i].setSize(20,30);
		}

		
		lab6=new JLabel("ʱ");
		lab7=new JLabel("��");
		lab8=new JLabel("��");
		lab2=new JLabel ("����ʱ��");
		lab6.setForeground(Color.WHITE);//ǰ��ɫ
		lab7.setForeground(Color.WHITE);
		lab8.setForeground(Color.WHITE);
		lab2.setForeground(Color.WHITE);

		b1.setBounds(150,0,40,27);//��ťλ�ü���С
	    b2.setBounds(200,0,40,27);
		b1.setIcon(icon);
		b2.setIcon(icon1);
		setLayout(new BorderLayout());
		b1.addActionListener(//Ϊ��ť���������
				new ActionListener()
				{
					public void actionPerformed(ActionEvent e)
					{
						
							flag=true;//���ı���flag���ڿ����Ƿ������ӹ���trueΪ����
                        
						for(int i=0;i<3;i++)
						{
							t[i]=time[i].getText();//��ȡ�趨��ʱ��
						  
						    	
						}
						
						
					}
					
				});
		b2.addActionListener(
				new ActionListener()
				{
					
					public void actionPerformed(ActionEvent e)
					{
						try
						{
						flag=false;
					    clip.stop();
					    flag2=false;
					    count=0;
					    
					    }
						catch(NullPointerException e1)//��ȡ�쳣
						{
							JOptionPane.showMessageDialog(null,"�����趨����");//�쳣����
						}

					}
					
				});
		box=new JComboBox(songs);//ѡ������
		box.setMaximumRowCount(3);//ѡ��һ�������ʾ������
		
		box.addItemListener(//Ϊѡ����������
				new ItemListener()
				{
				public void itemStateChanged(ItemEvent e)
				{
					if(e.getStateChange()==ItemEvent.SELECTED)
						song=new String().valueOf(e.getItem());//song���¸�ֵ
				}} );
	
		for(int k=0;k<2;k++)
		{
			p[k]=new JPanel();
		}
		 p[1].setLayout(null);
		p[0].add(lab2);p[0].add(time[0]);p[0].add(lab6);p[0].add(time[1]);p[0].add(lab7);p[0].add(time[2]);p[0].add(lab8);p[0].add(box);
		p[1].add(b1);p[1].add(b2);
		back.setLayout(null);
		add(back);
		p[0].setOpaque(false);//����pΪ͸���������������Բ����ڸǱ���ͼ
		p[1].setOpaque(false);
		p[0].setForeground(Color.WHITE);//ǰ��ɫ
		p[0].setBounds(0,35,410,30);
		p[1].setBounds(0,300,410,30);
		back.add(p[0]);
		
		back.add(p[1]);
		
		
	}
      public void Alarm() throws MalformedURLException, InterruptedException
   {
	    try
	    {
    	  int i = 0;
	     
    	  
    	  if(flag==true)
    	  {
    		  
    		  //�ж��Ƿ�ִ������
    		   if(new Integer(t[0])==c.h)
    			  if(new Integer(t[1])==c.mi)
    				  if(new Integer(t[2])==c.s)
    				  {
    					  //�������ļ������������ļ�����ΪMP3��wma��
    					  musicfile=new File(song);
    						uri=musicfile.toURI();
    						url=uri.toURL(); 
    					  
    						
    					 clip=Applet.newAudioClip(url);
                        clip.play();
                        i=JOptionPane.showConfirmDialog(null, "���ˣ�","Alarm",JOptionPane.YES_NO_OPTION);//����������ѡ��
                        if(i==JOptionPane.YES_OPTION)//ѡ��yes����ֹͣ
            		    { 
            		       clip.stop();
                           flag2 = false;//flag2Ϊ�����������ı���
                           count = 0;//����ʱ����Ʊ���
                           count1=0;//������Ʊ���
                         }
                        if(i==JOptionPane.NO_OPTION)//ѡno��ʱֹͣ����
                        {
                        	clip.stop();
                        }
                        flag2 = true; //���ֲ���ʱ����Ʊ���
                  }
    		    
                 if(flag2)
                 { count++;count1++;}//ʱ����Ʊ���������ͳ������ʱ����������
                 if(count == 180)//������3���Ӻ�ֹͣ
                 {
                    clip.stop();
                    flag2 = false;
                    count = 0;
                 }
                 if(count1==60)//ÿ��һ��������һ��
                 {
                	 clip.play();
                	 i=JOptionPane.showConfirmDialog(null, "���ˣ�","Alarm",JOptionPane.YES_NO_OPTION);
                     if(i==JOptionPane.YES_OPTION)
         		    { 
         		       clip.stop();
                        flag2 = false;
                        count = 0;
                        count1=0;
                      }
                     if(i==JOptionPane.NO_OPTION)
                     {
                     	clip.stop();
                     	count1=0;
                     }
                     
                     
                 }
                    
                
    				
    	  }
	    }

		catch(NumberFormatException e2)//�쳣����
		{
			JOptionPane.showMessageDialog(null,"�����趨����");
			flag=false;
		}
		
   }
	public void run()//�̲߳���
			{
			     while(true)
			        {
			        try{
			        	    cal=Calendar.getInstance(); 
				            h=cal.get(Calendar.HOUR_OF_DAY); 
				            mi=cal.get(Calendar.MINUTE); 
				            s=cal.get(Calendar.SECOND);
			        	     Alarm();//����alarm
			        	     Thread.sleep(1000);
					    }
			        catch (InterruptedException ex)
			            {
			            
							ex.printStackTrace();
						
			            } catch (MalformedURLException e) {
						// TODO Auto-generated catch block
						e.printStackTrace();
					}

			       }
	}
	@Override
	public void play() {
		// TODO Auto-generated method stub
		
	}
	@Override
	public void loop() {
		// TODO Auto-generated method stub
		
	}
	@Override
	public void stop() {
		// TODO Auto-generated method stub
		
	}
}
