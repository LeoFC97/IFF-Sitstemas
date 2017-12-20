package Interface;

import java.lang.reflect.Method;
import javax.swing.JOptionPane;
public class Git extends javax.swing.JFrame {
    public Git() {
        initComponents();
    }
    private void initComponents() {
        jButton1 = new javax.swing.JButton();
        jTextField1 = new javax.swing.JTextField();
        setTitle("Codigo Fonte");
        jButton1.setText("Abrir link");
        jButton1.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jButton1ActionPerformed(evt);
            }
        });
        jTextField1.setText("https://github.com/leonardofernandescosta/3-Semestre-Sistemas-de-Informa-o/tree/master/Trabalho_Java_1");
        jTextField1.setEditable(false);
        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addGroup(layout.createSequentialGroup()
                        .addContainerGap()
                        .addComponent(jTextField1, javax.swing.GroupLayout.DEFAULT_SIZE, 216, Short.MAX_VALUE))
                    .addGroup(layout.createSequentialGroup()
                        .addGap(55, 55, 55)
                        .addComponent(jButton1)))
                .addContainerGap())
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addContainerGap()
                .addComponent(jTextField1, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addComponent(jButton1)
                .addContainerGap(javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
        );
        pack();
    }
    private void jButton1ActionPerformed(java.awt.event.ActionEvent evt) {
        openURL(jTextField1.getText().trim()); 
    }
    private static final String errMsg = "Erro ao tentar abrir o browser";
    public static void openURL(String url) {
        String osName = System.getProperty("os.name");
        String browser = null;
        try {
            if (osName.startsWith("Mac OS")) { //Mac
                Class fileMgr = Class.forName("com.apple.eio.FileManager");
                Method openURL = fileMgr.getDeclaredMethod("openURL",
                        new Class[]{String.class});
                openURL.invoke(null, new Object[]{url});
            } else if (osName.startsWith("Windows")) {//Windows 
                Runtime.getRuntime().exec("rundll32 url.dll,FileProtocolHandler " + url);
            } else { //Linux or Unix
                String[] browsers = {
                    "firefox", "opera", "konqueror", "epiphany", "mozilla", "netscape"
                };
                for (int count = 0; count < browsers.length && browser == null; count++) {
                    if (Runtime.getRuntime().exec(
                            new String[]{"which", browsers[count]}).waitFor() == 0) {
                        browser = browsers[count];
                    }
                }
                JOptionPane.showMessageDialog(null,browser);
                if (browser == null) {
                    JOptionPane.showMessageDialog(null,"Navegador não encontrado!");
                } else {
                    Runtime.getRuntime().exec(new String[]{browser,url});
                }
            }
        } catch (Exception e) {
            JOptionPane.showMessageDialog(null, errMsg + ":\n" + e.getLocalizedMessage());
        }
    }
    public javax.swing.JButton jButton1;
    public javax.swing.JTextField jTextField1;
}