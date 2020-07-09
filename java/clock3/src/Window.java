import java.awt.*;

import javax.swing.*;

import java.net.MalformedURLException;
import java.util.concurrent.*;
public class Window extends JFrame {
	public Window() throws MalformedURLException
	{
		super("����");
		JTabbedPane Pane=new JTabbedPane();//��ǩ
		Clock clock=new Clock();
		Time time=new Time(clock);
		clock.q.setOpaque(false);//���ñ���͸��
		clock.q.setBounds(0,0,410,30);
		time.back.add(clock.q);
		ExecutorService threadExecutor =Executors.newFixedThreadPool(2);//�̳߳�
		threadExecutor.execute(clock);//�߳̿���
		threadExecutor.execute(time);
		Pane.addTab("����ʱ��",null,clock);//��ǩ�趨
		Pane.addTab("�����趨",null,time);
		threadExecutor.shutdown();
		add(Pane);
		setBounds(100, 100, 410, 435);//�����Ϊ��������ʾ����λ�ü����С
		setResizable(false);
		setVisible(true);
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	
		
	}
	public static void main(String[] args) throws MalformedURLException {
		new Window();
	}
}
