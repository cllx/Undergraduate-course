import java.awt.*;

import java.awt.event.*;

import javax.swing.*;

public class JCalculator extends JFrame implements ActionListener {

    //������ǹرմ����õ�

    private class WindowCloser extends WindowAdapter {

       public void windowClosing(WindowEvent we) {

           System.exit(0);

       }

    }

    int i;
    
    //����ַ����ǰ�ť

    private final String[] str = { "1", "2", "3", "/", "4", "5", "6", "*", "7",

           "8", "9", "-", ".", "0", "=", "+" };

    //������ť

    JButton[] buttons = new JButton[str.length];

    //���㰴ť

    JButton reset = new JButton("����");

    //���㰴ť
    
    //�����ı�����ʾ������̺ͽ��

    JTextField display = new JTextField("0");

    //�޲������캯��

    public JCalculator() {

       super("Calculator");

       //���һ�����

       JPanel panel1 = new JPanel(new GridLayout(4, 4, 3, 3));

       //�������Ĳ��ֹ�����Ϊ��������ֹ�����

       for (i = 0; i < str.length; i++) {

           buttons[i] = new JButton(str[i]);

           panel1.add(buttons[i]);

       }

       //�����һ�����
       
       JPanel panel2 = new JPanel(new BorderLayout());

       //������岼�ֹ�����Ϊ�߽粼�ֹ�����������ʾ�ı�������õ������ӵ���������

       panel2.add("Center", display);
       
       panel2.add("East", reset);

       getContentPane().setLayout(new BorderLayout());
       
       //��getContentPane()����������1��ӵ��м䣬�����2��ӵ�����
       
       //�������Ĵ�С
       panel2.setPreferredSize(new Dimension(40, 40));
       
       panel1.setPreferredSize(new Dimension(350, 300));

       getContentPane().add("North", panel2);

       getContentPane().add("Center", panel1);

       //Ϊÿһ����ť��Ӽ�����

       for (i = 0; i < str.length; i++)

           buttons[i].addActionListener(this);

       //Ϊ���ð�ť���һ��������

       reset.addActionListener(this);

       //Ϊ��ʾ�����һ��������

       display.addActionListener(this);

       //��Ӵ��ڼ�����(�رմ���)

       addWindowListener(new WindowCloser());

       //��ʼ�����ڴ�С

       setBounds(100,100,1200,1500);

       //����ʹ���ڿɼ�

       setVisible(true);

       //���һ���ĳߴ�

       pack();

    }   

    //������������ʱ������Ӧ
    
    public void actionPerformed(ActionEvent e) {

       Object target = e.getSource();

       String label = e.getActionCommand();

       if (target == reset)

           handleReset();

       else if ("0123456789.".indexOf(label) >= 0)

           handleNumber(label);

       else

           handleOperator(label);

    }

    //�жϵ�һ�������Ƿ񱻰���

    boolean isFirstDigit = true;
    
    boolean flag = false;

    //���������ֵĶ���

    public void handleNumber(String key) {

       if (isFirstDigit)

           display.setText(key);

       else if ((key.equals(".")) && (display.getText().indexOf(".") < 0))

           display.setText(display.getText() + ".");

       else if (!key.equals("."))

           display.setText(display.getText() + key);

       isFirstDigit = false;

    }

    //����������ʱ�Ķ���

    public void handleReset() {

       display.setText("0");

       isFirstDigit = true;

       operator = "=";

    }
    
    double number = 0.0;

    String operator = "=";

    //�����������

    public void handleOperator(String key) {

       if (operator.equals("+"))

           number += Double.valueOf(display.getText());

       else if (operator.equals("-"))

           number -= Double.valueOf(display.getText());

       else if (operator.equals("*"))

           number *= Double.valueOf(display.getText());

       else if (operator.equals("/")){
    	   
    	   if(Double.valueOf(display.getText()) == 0){
    		   
    		   JOptionPane.showMessageDialog(buttons[14], "0����������", "����",JOptionPane.WARNING_MESSAGE);
    	   
    		   flag = true;
    	   }
    	   
    	   else

               number /= Double.valueOf(display.getText());
          
       }

       else if (operator.equals("=")){
    	   
    	   if(flag){
    		   
    		   display.setText("0");
    	   
    	   }
    	   
    	   flag = false;
    	   
           number = Double.valueOf(display.getText());
           
       }

       display.setText(String.valueOf(number));

       operator = key;

       isFirstDigit = true;

    }

    public static void main(String[] args) {

       new JCalculator();

    }

}

