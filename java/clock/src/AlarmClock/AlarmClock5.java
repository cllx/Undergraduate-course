package AlarmClock;
import java.awt.*;
import java.awt.event.*;
import java.util.*;
import javax.swing.*;
import javax.swing.Timer;

public class AlarmClock5 extends JFrame implements ActionListener {
 public final int HEIGTH = 200, L0 = 50, T0 = 50,N=8;  
 public final double RAD = Math.PI / 180.0;
 int x, y, old_X, old_Y, r, x0, y0, w, h, ang;
 int sdo, mdo, hdo, old_M, old_H, hh, mm, ss;
 int delay = 1000;
 Calendar now;
 String st, alarm, Items1, Items2,str[];
 JButton jb;
 JComboBox jc1, jc2, jc3;
 JLabel jl1, jl2, jl3, jl4;
 JMenu jm1, jm2, jm3, jm4;
 JMenuBar jmb;
 JMenuItem jmi1, jmi2, jmi3, jmi4, jmi5, jmi6, jmi7, jmi8, jmi9,jmi10;
 JTextField jtf1, jtf2, time;
 JPanel jp1, jp2, jp3;
 Timer timer;
 TimeZone tz = TimeZone.getTimeZone("JST");
 Toolkit toolkit=Toolkit.getDefaultToolkit();;
 /**
  * <br>
  * ����˵����ʵ��ActionListener�������صķ���
  */

 public static void main(String[] args) {
	 AlarmClock5 cp = new AlarmClock5();
  cp.setVisible(true);
 }

 AlarmClock5() {
  super("Java���ӣ�");
  setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
  setSize(550, 700);
  setVisible(true);
  Container contentPane = getContentPane();

  jp2 = new JPanel();

  jmb = new JMenuBar();

  jm1 = new JMenu("������ɫ����                     ", true);
  jmi1 = new JMenuItem("��Ȧ��ɫ");
  jmi1.addActionListener(this);
  jmi1.setActionCommand("color1");
  jm1.add(jmi1);
  jmi2 = new JMenuItem("���ӱ�����ɫ");
  jmi2.addActionListener(this);
  jmi2.setActionCommand("color2");
  jm1.add(jmi2);
  jmi3=new JMenuItem("������ɫ");
  jmi3.addActionListener(this);
  jmi3.setActionCommand("color3");
  jm1.add(jmi3);
  jmi4=new JMenuItem("ϵͳʱ�䱳����ɫ");
  jmi4.addActionListener(this);
  jmi4.setActionCommand("color4");
  jm1.add(jmi4);
  jmb.add(jm1);

  jm2 = new JMenu("ָ����ɫ����                          ", true);
  jmi5 = new JMenuItem("������ɫ");
  jmi5.addActionListener(this);
  jmi5.setActionCommand("color5");
  jm2.add(jmi5);
  jmi6 = new JMenuItem("������ɫ");
  jmi6.addActionListener(this);
  jmi6.setActionCommand("color6");
  jm2.add(jmi6);
  jmi7 = new JMenuItem("ʱ����ɫ");
  jmi7.addActionListener(this);
  jmi7.setActionCommand("color7");
  jm2.add(jmi7);
  jmb.add(jm2);

  jm3 = new JMenu("������������                         ", true);
  jmi8 = new JMenuItem("����1");
  jmi8.addActionListener(this);
  jmi8.setActionCommand("ring1");
  jm3.add(jmi8);
  jmi9 = new JMenuItem("����");
  jmi9.addActionListener(this);
  jmi9.setActionCommand("ring2");
  jm3.add(jmi9);
  jmb.add(jm3);

  jm4 = new JMenu("����            ", true);
  jmi10=new JMenuItem("ʹ��˵��");
  jmi10.addActionListener(this);
  jmi10.setActionCommand("help");
  jm4.add(jmi10);
  jmb.add(jm4);
  jp2.add(jmb);

  contentPane.add(jp2, BorderLayout.NORTH);

  jp3 = new JPanel();
  jl1 = new JLabel("����ʱ��");
  jl1.setFont(new Font("����_GB2312", Font.BOLD, 18));
  time = new JTextField("00:00", 5);
  alarm = time.getText();
  jb = new JButton("�޸�����ʱ��");
  jb.addActionListener(this);
  jb.setActionCommand("CC");
  jp3.add(jl1);
  jp3.add(time);
  jp3.add(jb);
  contentPane.add(jp3, BorderLayout.SOUTH);

  ClockPanel clock = new ClockPanel();
  contentPane.add(clock, BorderLayout.CENTER);

  // ��������¼��������������Ĵ���
  ActionListener taskPerformer = new ActionListener() {
   public void actionPerformed(ActionEvent evt) {
    repaint();
   }
  };
  new Timer(delay, taskPerformer).start();
 }

 /**
  * <br>
  * ����˵��������ͼ��
  */

 Color C1 = Color.lightGray;// ��Ȧ��ɫ
 Color C2 = Color.black;// ������ɫ
 Color C3 = Color.magenta;// ������ɫ
 Color C4 = Color.blue;// ������ɫ
 Color C5 = Color.yellow;// ������ɫ
 Color C6 = Color.green;// ������ɫ
 Color C7 = Color.red;//ʱ����ɫ
 public class ClockPanel extends JPanel {
  public void paint(Graphics g) {
   h = getSize().height - 200;
// ����Բ��
   g.setColor(C1);
   g.fillOval(L0 + 30, T0 + 30, h - 60, h - 60);
   g.setColor(C2);
   g.drawOval(L0 + 31, T0 + 31, h - 62, h - 62);
   g.setColor(C3);
   g.fillOval(L0 + 50, T0 + 50, h - 100, h - 100);
   g.setColor(C2);
   g.drawOval(L0 + 51, T0 + 51, h - 102, h - 102);
 
   r = h / 2 - 30;
   x0 = 30 + r - 5 + L0;
   y0 = 30 + r - 5 - T0;
   ang = 60;
   for (int i = 1; i <= 12; i++) {
    x = (int) ((r - 10) * Math.cos(RAD * ang) + x0);
    y = (int) ((r - 10) * Math.sin(RAD * ang) + y0);
    g.drawString("" + i, x, h - y);
    ang -= 30;
   }
   x0 = 30 + r + L0;
   y0 = 30 + r + T0;
   g.drawString("ָ��ʽʱ��", 215, 200);

   // ��ȡʱ��
   now = Calendar.getInstance();
   hh = now.get(Calendar.HOUR_OF_DAY);// Сʱ
   mm = now.get(Calendar.MINUTE);// ����
   ss = now.get(Calendar.SECOND);// ��
   g.setColor(C4);
   g.fillRect(5, 550, 150, 30);// ���ľ���
   g.setColor(C6);
   if (hh < 10)
    st = "0" + hh;
   else
    st = "" + hh;
   if (mm < 10)
    st = st + ":0" + mm;
   else
    st = st + ":" + mm;
    if(alarm.equals(st))
    { 
    if(toolkit!=null)
     toolkit.beep(); 
    else   {}
    }
   if (ss < 10)
    st = st + ":0" + ss;
   else
    st = st + ":" + ss;
   {
    g.setFont(new Font("���Ŀ���", Font.BOLD, 16));
    g.drawString("ϵͳʱ��:" + st, 10, 570);
   }

   // ����ʱ���ͼ�εĹ�ϵ
   sdo = 90 - ss * 6;
   mdo = 90 - mm * 6;
   hdo = 90 - hh * 30 - mm / 2;
   // ��������
   if (old_X > 0) {
    g.setColor(C3);
   } else {
    old_M = mdo;
    old_H = hdo;
   }
   // ��������
   g.setColor(C5);
   x = (int) ((r - 26) * Math.cos(RAD * sdo) + x0);
   y = (int) ((r - 26) * Math.sin(RAD * sdo) + y0) - 2 * T0;
   g.drawLine(x0, y0, x, (h - y));

   old_X = x;
   old_Y = y;

   // ���������ʱ��
   if (mdo != old_M) {
    g.setColor(C3);
    old_M = mdo;
   }
   if (hdo != old_H) {
    g.setColor(C3);
    old_H = hdo;
   }
   // ���Ʒ���
   g.setColor(C6);
   x = (int) ((r - 50) * Math.cos(RAD * mdo) + x0);
   y = (int) ((r - 50) * Math.sin(RAD * mdo) + y0) - 2 * T0;
   g.drawLine(x0, y0, x, (h - y));
   // ����ʱ��
   g.setColor(C7);
   x = (int) ((r - 90) * Math.cos(RAD * hdo) + x0);
   y = (int) ((r - 90) * Math.sin(RAD * hdo) + y0) - 2 * T0;
   g.drawLine(x0, y0, x, (h - y));
  } // end paint
 }

 // ����ʱ����жϼ�ʵ��
 // ����������ʵ��

 public void actionPerformed(ActionEvent e) {
//  JMenuItem m = (JMenuItem) e.getSource();

  if (e.getActionCommand() == "CC") {
   int newHou, newMin;
   char c;
   
   String getTime = JOptionPane.showInputDialog(this, "����������ʱ���ʽ�磺", "00:00");
   repaint();
 
//�����������ʱ�䣬��ʲô��ӡnull
   if(getTime==null)
    System.out.println(getTime);
//   dispose();
             
   judge: if (getTime != null) {
    //��ӡ��������õ�ʱ��   
    System.out.println(getTime);
    // �ж�������ǲ���5λ�ַ�
    if (getTime.length() != 5) {
     JOptionPane.showMessageDialog(time, "��ʽ����\n�밴��ʽ����5λ����", "Error",
       JOptionPane.ERROR_MESSAGE);
     repaint();
     break judge;
    }

    // �ж�������ǲ�������
    for (int i = 0; i < (getTime.length()); i++) {
     c = getTime.charAt(i);
     if (i == 2 && !Character.isDigit(c))
      continue;
     // �жϵ�ǰ�ַ�,��������������������¼�
     if (i != 2 && !Character.isDigit(c)) {
      JOptionPane.showMessageDialog(this, "��ʽ����\n�밴��ʽ����5λ����",
        "Error",JOptionPane.ERROR_MESSAGE);
      repaint();
      break judge;
     }
    }
    char[] hour = { getTime.charAt(0), getTime.charAt(1) };
    char[] minute = { getTime.charAt(3), getTime.charAt(4) };
    newHou = Integer.parseInt(String.valueOf(hour));
    newMin = Integer.parseInt(String.valueOf(minute));
    if (newHou >= 24 || newHou < 0) {
     JOptionPane.showMessageDialog(this, "��ʽ����\nСʱӦ���ǲ�С��0������23������",
       "Error", JOptionPane.ERROR_MESSAGE);
     repaint();
     break judge;
    }
    if (newMin >= 60 || newHou < 0) {
     JOptionPane.showMessageDialog(this, "��ʽ����\n����Ӧ����С��60������", "Error",
       JOptionPane.ERROR_MESSAGE);
     repaint();
     break judge;
    }
    new SetTime(newHou, newMin);
   }
  }

if (e.getActionCommand() == "ring1") {
   toolkit=Toolkit.getDefaultToolkit();
  }
  if(e.getActionCommand() == "ring2"){
   System.out.println("����");
   toolkit=null;

  }
  
  if (e.getActionCommand() == "color1") {
   String color;
   Color c;
   System.out.println("color1");
   color = JOptionPane.showInputDialog(this, "������ϲ������Ȧ��ɫ��0--255��", "128");
   if (color == null) {
   } else {
    if (Integer.parseInt(color) < 0
      || Integer.parseInt(color) > 255)
     JOptionPane.showInputDialog(this, "������ϲ������Ȧ��ɫ��0--255��", "128");
    else {
     c = new Color(Integer.parseInt(color));
     C1 = c;
    }
   }
  }
  if(e.getActionCommand() == "color2"){
   String color;
   Color c;
   System.out.println("color2");
   color = JOptionPane.showInputDialog(this, "������ϲ���ı�����ɫ��0--255��", "128");
   if(color==null){}
   else{if (Integer.parseInt(color) < 0|| Integer.parseInt(color) > 255)
         JOptionPane.showInputDialog(this, "������ϲ���ı�����ɫ��0--255��", "128");
        else {
            c = new Color(Integer.parseInt(color));
            C2 = c;
   } 
    }
  }
  if(e.getActionCommand() == "color3"){
   String color;
   Color c;
   System.out.println("color3");
   color = JOptionPane.showInputDialog(this, "������ϲ����������ɫ��0--255��", "128");
   if(color==null){}
   else{if (Integer.parseInt(color) < 0|| Integer.parseInt(color) > 255)
         JOptionPane.showInputDialog(this, "������ϲ����������ɫ��0--255��", "128");
        else {
            c = new Color(Integer.parseInt(color));
            C3 = c;
   } 
    }
 }
  
  if(e.getActionCommand() == "color4"){
   String color;
   Color c;
   System.out.println("color4");
   color = JOptionPane.showInputDialog(this, "������ϲ���ı�����ɫ��0--255��", "128");
   if(color==null){}
   else{if (Integer.parseInt(color) < 0|| Integer.parseInt(color) > 255)
         JOptionPane.showInputDialog(this, "������ϲ���ı�����ɫ��0--255��", "128");
        else {
            c = new Color(Integer.parseInt(color));
            C4 = c;
           } 
    }
   }
  if(e.getActionCommand() == "color5"){
   String color;
   Color c;
   System.out.println("color5");
   color = JOptionPane.showInputDialog(this, "������ϲ����������ɫ��0--255��", "128");
   if(color==null){}
   else{if (Integer.parseInt(color) < 0|| Integer.parseInt(color) > 255)
         JOptionPane.showInputDialog(this, "������ϲ����������ɫ��0--255��", "128");
        else {
            c = new Color(Integer.parseInt(color));
            C5 = c;
           } 
    }
   }
  if(e.getActionCommand() == "color6"){
   String color;
   Color c;
   System.out.println("color6");
   color = JOptionPane.showInputDialog(this, "������ϲ���ķ�����ɫ��0--255��", "128");
   if(color==null){}
   else{if (Integer.parseInt(color) < 0|| Integer.parseInt(color) > 255)
         JOptionPane.showInputDialog(this, "������ϲ���ķ�����ɫ��0--255��", "128");
        else {
            c = new Color(Integer.parseInt(color));
            C6 = c;
           } 
    }
   }
  
  if(e.getActionCommand() == "color7"){
   String color;
   Color c;
   System.out.println("color7");
   color = JOptionPane.showInputDialog(this, "������ϲ����ʱ����ɫ��0--255��", "128");
   if(color==null){}
   else{if (Integer.parseInt(color) < 0|| Integer.parseInt(color) > 255)
         JOptionPane.showInputDialog(this, "������ϲ����ʱ����ɫ��0--255��", "128");
        else {
            c = new Color(Integer.parseInt(color));
            C7 = c;
           } 
    }
   }

if(e.getActionCommand() == "help"){
     String help;
  help = JOptionPane.showInputDialog(this, "����quit�˳������ӵ�ʹ��", "����������Java�е�ָ��ʽʱ��");
     if(help.equals("quit"))
      dispose();
     else {}
//  timer.restart();
 }
 }
 
 class SetTime {
  String Hour;
  String Minute;

  public SetTime() { }
  public SetTime(int hour, int minute) {
   // ��ʱ�����С��10��ʱ����ǰ������ַ�0
   if (hour < 10) {
    Hour = "0" + String.valueOf(hour);
   } else {
    Hour = "" + String.valueOf(hour);
   }
   if (minute < 10) {
    Minute = "0" + String.valueOf(minute);
   } else {
    Minute = "" + String.valueOf(minute);
   }
   alarm = Hour + ":" + Minute;
   time.setText(alarm);
   repaint();
  }
 }
}