package MQ;

import javax.jms.JMSException;
import javax.jms.Message;
import javax.jms.Session;
import javax.jms.TextMessage;
import com.ibm.mq.jms.MQQueue;
import com.ibm.mq.jms.MQQueueConnection;
import com.ibm.mq.jms.MQQueueConnectionFactory;
import com.ibm.mq.jms.MQQueueReceiver;
import com.ibm.mq.jms.MQQueueSession;

public class MQStub {

    public static void main(String[] args) {
        try {
            MQQueueConnection mqConn;
            MQQueueConnectionFactory mqCF;
            MQQueueSession mqQSession;
            MQQueue mqIn;
            MQQueueReceiver mqReceiver;

            // Создание фабрики соединений
            mqCF = new MQQueueConnectionFactory();
            mqCF.setHostName("localhost");
            mqCF.setPort(1410);
            mqCF.setQueueManager("MQtester");
            mqCF.setChannel("SYSTEM.DEF.CLNTCONN"); // Убедитесь, что используете правильный канал

            // Создание соединения и сессии
            System.out.println("Connecting to MQ...");
            mqConn = (MQQueueConnection) mqCF.createQueueConnection();
            System.out.println("Connected to MQ!");

            mqQSession = (MQQueueSession) mqConn.createQueueSession(false, Session.AUTO_ACKNOWLEDGE);

            // Создание очереди и получателя
            mqIn = (MQQueue) mqQSession.createQueue("MQ.IN"); // Убедитесь, что имя очереди правильное
            mqReceiver = (MQQueueReceiver) mqQSession.createReceiver(mqIn);

            // Реализация слушателя сообщений
            mqReceiver.setMessageListener(new javax.jms.MessageListener() {
                @Override
                public void onMessage(Message msg) {
                    System.out.println("Got message!");
                    if (msg instanceof TextMessage) {
                        try {
                            TextMessage tMsg = (TextMessage) msg;
                            String msgText = tMsg.getText();
                            System.out.println("Message content: " + msgText);
                        } catch (JMSException e) {
                            e.printStackTrace();
                        }
                    } else {
                        System.out.println("Non-text message received.");
                    }
                }
            });

            // Запуск соединения
            mqConn.start();
            System.out.println("Stub Started. Waiting for messages...");

            // Удерживаем программу активной для получения сообщений
            Thread.sleep(60000);

            // Закрытие ресурсов
            mqReceiver.close();
            mqQSession.close();
            mqConn.close();
            System.out.println("Stub stopped.");

        } catch (JMSException e) {
            e.printStackTrace();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }
}
