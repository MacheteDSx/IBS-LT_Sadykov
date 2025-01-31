package MQ;

import javax.jms.*;
import com.ibm.mq.jms.*;

public class MQClient {

    public static void main(String[] args) {
        try {
            MQQueueConnection mqConn;
            MQQueueConnectionFactory mqCF;
            MQQueueSession mqQSession;
            MQQueue mqIn, mqOut;
            MQQueueReceiver mqReceiver;
            MQQueueSender mqSender;

            // Создание фабрики соединений
            mqCF = new MQQueueConnectionFactory();
            mqCF.setHostName("localhost");
            mqCF.setPort(1410);
            mqCF.setQueueManager("MQtester");
            mqCF.setChannel("SYSTEM.DEF.SVRCONN");

            // Создание соединения и сессии
            mqConn = (MQQueueConnection) mqCF.createQueueConnection();
            mqQSession = (MQQueueSession) mqConn.createQueueSession(false, Session.AUTO_ACKNOWLEDGE);

            // Создание очередей (входной и выходной)
            mqIn = (MQQueue) mqQSession.createQueue("queue:///MQ.IN");
            mqOut = (MQQueue) mqQSession.createQueue("queue:///MQ.OUT");

            // Создание получателя и отправителя
            mqReceiver = (MQQueueReceiver) mqQSession.createReceiver(mqIn);
            mqSender = (MQQueueSender) mqQSession.createSender(mqOut);

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

                            // Пересылаем сообщение в выходную очередь
                            TextMessage outMsg = mqQSession.createTextMessage(msgText);
                            mqSender.send(outMsg);
                            System.out.println("Message forwarded to MQ.OUT");
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
            System.out.println("Client Started. Waiting for messages...");

            // Удерживаем программу активной для получения сообщений
            Thread.sleep(60000);

            // Закрытие ресурсов
            mqReceiver.close();
            mqSender.close();
            mqQSession.close();
            mqConn.close();
            System.out.println("Client stopped.");

        } catch (JMSException | InterruptedException e) {
            e.printStackTrace();
        }
    }
}
