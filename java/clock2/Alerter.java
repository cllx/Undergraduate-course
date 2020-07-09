import java.awt.AWTException;
import java.awt.FlowLayout;
import java.awt.Frame;
import java.awt.Image;
import java.awt.SystemTray;
import java.awt.Toolkit;
import java.awt.TrayIcon;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
//Download by http://www.codefans.net
import javax.swing.JButton;
import javax.swing.JComboBox;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JTextField;
import javax.swing.Timer;

public class Alerter extends JFrame implements ActionListener {
	private Image image;// 托盘图标
	private TrayIcon trayIcon;
	private SystemTray systemTray;// 系统托盘

	int alertInterval = 0;
	final String[] in = { "周", "日", "时", "分", "秒" };
	final int ONEDAYMILLISECONDS = 24 * 3600 * 1000;
	final int[] milliSeconds = { 7 * this.ONEDAYMILLISECONDS,
			this.ONEDAYMILLISECONDS, 3600 * 1000, 60 * 1000, 1000 };

	Timer timer;
	JLabel time;
	JLabel interval;
	JTextField msg;
	JTextField tf;
	JComboBox cb;
	JButton button;

	Alerter() {
		systemTray = SystemTray.getSystemTray();// 获得系统托盘的实例
		try {
			image = Toolkit.getDefaultToolkit().getImage(
					getClass().getResource("temp.jpg"));// 定义托盘图标的图片
			trayIcon = new TrayIcon(image, "系统托盘");
			systemTray.add(trayIcon);
		} catch (AWTException e2) {
			e2.printStackTrace();
		}
		trayIcon.addMouseListener(new MouseAdapter() {
			public void mouseClicked(MouseEvent e) {
				if (e.getClickCount() == 2)// 双击托盘窗口再现
					setExtendedState(Frame.NORMAL);// 状态
				setVisible(true);
			}
		});

		time = new JLabel("请输入提示信息：");
		interval = new JLabel("提醒周期：");
		msg = new JTextField(12);
		tf = new JTextField(10);
		cb = new JComboBox(in);
		cb.setSelectedIndex(2);
		button = new JButton("确定");
		button.addActionListener(this);

		this.setTitle("定时提醒器");
		this.setBounds(200, 150, 300, 250);
		this.setVisible(true);
		this.setLayout(new FlowLayout());
		this.setResizable(false);
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

		this.addWindowListener(new WindowAdapter() {
			public void windowIconified(WindowEvent e) {
				dispose();// 窗口最小化时dispose该窗口
			}
		});

		this.add(time);
		this.add(msg);
		this.add(interval);
		this.add(tf);
		this.add(cb);
		this.add(button);

		tf.requestFocus();
	}

	public void actionPerformed(ActionEvent e) {
		if (e.getSource() == button) {
			if (!tf.getText().equals("")) {
				int idx = cb.getSelectedIndex();
				this.alertInterval = Integer.parseInt(tf.getText())
						* this.milliSeconds[idx];
				if (timer == null) {
					timer = new Timer(this.alertInterval, this);
				} else {
					timer.setDelay(this.alertInterval);
				}
				timer.start();
			}
		} else if (e.getSource() == timer) {
			JOptionPane.showMessageDialog(this, msg.getText(), "叮呤呤!",
					JOptionPane.DEFAULT_OPTION);
		}
	}

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		new Alerter();
	}

}
