import java.awt.*;

import java.awt.event.*;

import javax.swing.*;

public class JCalculator extends JFrame implements ActionListener {

    //这个类是关闭窗口用的

    private class WindowCloser extends WindowAdapter {

       public void windowClosing(WindowEvent we) {

           System.exit(0);

       }

    }

    int i;
    
    //这个字符串是按钮

    private final String[] str = { "1", "2", "3", "/", "4", "5", "6", "*", "7",

           "8", "9", "-", ".", "0", "=", "+" };

    //创建按钮

    JButton[] buttons = new JButton[str.length];

    //清零按钮

    JButton reset = new JButton("重置");

    //清零按钮
    
    //创建文本框显示计算过程和结果

    JTextField display = new JTextField("0");

    //无参数构造函数

    public JCalculator() {

       super("Calculator");

       //添加一个面板

       JPanel panel1 = new JPanel(new GridLayout(4, 4, 3, 3));

       //设置面板的布局管理器为网格包布局管理器

       for (i = 0; i < str.length; i++) {

           buttons[i] = new JButton(str[i]);

           panel1.add(buttons[i]);

       }

       //再添加一个面板
       
       JPanel panel2 = new JPanel(new BorderLayout());

       //设置面板布局管理器为边界布局管理器，将显示文本框和重置的组键添加到这个面板里

       panel2.add("Center", display);
       
       panel2.add("East", reset);

       getContentPane().setLayout(new BorderLayout());
       
       //在getContentPane()容器里把面板1添加到中间，将面板2添加到北部
       
       //设置面板的大小
       panel2.setPreferredSize(new Dimension(40, 40));
       
       panel1.setPreferredSize(new Dimension(350, 300));

       getContentPane().add("North", panel2);

       getContentPane().add("Center", panel1);

       //为每一个按钮添加监听器

       for (i = 0; i < str.length; i++)

           buttons[i].addActionListener(this);

       //为重置按钮添加一个监听器

       reset.addActionListener(this);

       //为显示框添加一个监听器

       display.addActionListener(this);

       //添加窗口监听器(关闭窗口)

       addWindowListener(new WindowCloser());

       //初始化窗口大小

       setBounds(100,100,1200,1500);

       //设置使窗口可见

       setVisible(true);

       //配合一定的尺寸

       pack();

    }   

    //当触发监听器时做出反应
    
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

    //判断第一个数字是否被按下

    boolean isFirstDigit = true;
    
    boolean flag = false;

    //处理按下数字的动作

    public void handleNumber(String key) {

       if (isFirstDigit)

           display.setText(key);

       else if ((key.equals(".")) && (display.getText().indexOf(".") < 0))

           display.setText(display.getText() + ".");

       else if (!key.equals("."))

           display.setText(display.getText() + key);

       isFirstDigit = false;

    }

    //处理按下重置时的动作

    public void handleReset() {

       display.setText("0");

       isFirstDigit = true;

       operator = "=";

    }
    
    double number = 0.0;

    String operator = "=";

    //处理运算符号

    public void handleOperator(String key) {

       if (operator.equals("+"))

           number += Double.valueOf(display.getText());

       else if (operator.equals("-"))

           number -= Double.valueOf(display.getText());

       else if (operator.equals("*"))

           number *= Double.valueOf(display.getText());

       else if (operator.equals("/")){
    	   
    	   if(Double.valueOf(display.getText()) == 0){
    		   
    		   JOptionPane.showMessageDialog(buttons[14], "0不能作除数", "标题",JOptionPane.WARNING_MESSAGE);
    	   
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

