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
	private Image image;// ����ͼ��
	private TrayIcon trayIcon;
	private SystemTray systemTray;// ϵͳ����

	int alertInterval = 0;
	final String[] in = { "��", "��", "ʱ", "��", "��" };
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
		systemTray = SystemTray.getSystemTray();// ���ϵͳ���̵�ʵ��
		try {
			image = Toolkit.getDefaultToolkit().getImage(
					getClass().getResource("temp.jpg"));// ��������ͼ���ͼƬ
			trayIcon = new TrayIcon(image, "ϵͳ����");
			systemTray.add(trayIcon);
		} catch (AWTException e2) {
			e2.printStackTrace();
		}
		trayIcon.addMouseListener(new MouseAdapter() {
			public void mouseClicked(MouseEvent e) {
				if (e.getClickCount() == 2)// ˫�����̴�������
					setExtendedState(Frame.NORMAL);// ״̬
				setVisible(true);
			}
		});

		time = new JLabel("��������ʾ��Ϣ��");
		interval = new JLabel("�������ڣ�");
		msg = new JTextField(12);
		tf = new JTextField(10);
		cb = new JComboBox(in);
		cb.setSelectedIndex(2);
		button = new JButton("ȷ��");
		button.addActionListener(this);

		this.setTitle("��ʱ������");
		this.setBounds(200, 150, 300, 250);
		this.setVisible(true);
		this.setLayout(new FlowLayout());
		this.setResizable(false);
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

		this.addWindowListener(new WindowAdapter() {
			public void windowIconified(WindowEvent e) {
				dispose();// ������С��ʱdispose�ô���
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
			JOptionPane.showMessageDialog(this, msg.getText(), "������!",
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
