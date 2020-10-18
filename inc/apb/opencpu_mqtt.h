/*******************************************************************************
 
 *******************************************************************************/
#ifndef __CMMQTT_OC_C_
#define __CMMQTT_OC_C_

/*****************************************************
��������:
server : ��������ַ
port: �˿ں�
client_id : �ͻ�id
keepAlive : ����ping�����
user: �û���
passwd:����
clean : ����ʱ�Ƿ����֮ǰ��seesion
���� :���óɹ�����0������ʧ�ܷ�������ֵ��
notice :����UNINITIALED ״̬ʱ�ſɽ�������
******************************************************/
int opencpu_mqttcfg(char* server, uint32_t port, char* client_id,  uint32_t keepAlive, char* user, char* passwd, uint32_t clean);

/*****************************************************
��������:
user_flag : �û���־(0-1)
pwd_flag:   �����־(0-1)
will_flag : willmsg��־(0-1)
retain_flag : �־û���־(0-1)
will_qos:  qos(0-2)
will_topic: willmsg topic
will_msg : willmsg
���� :����ɹ�����0��ʧ�ܷ�������ֵ���첽����ģʽ���������ӳɹ����жϸ����Ƿ��յ�MQTTOPEN:OK
notice: ����INITIALED ת̬�ƿɷ������ӣ����ӳɹ���״̬���ΪCONNECTED
******************************************************/
int opencpu_mqttopen(uint32_t user_flag, uint32_t pwd_flag, uint32_t will_flag, uint32_t retain_flag, uint32_t will_qos, char* will_topic, char* will_msg);

/*****************************************************
��ѯ��ǰmqtt client ״̬:
state : 
	UNINITIALED	 :0
	INITIALED	 :1
	DISCONNECTED :2
	CONNECTING   :3
	RECONNECTING :4
	CONNECTED    :5
	NET_CONNECTING: 6
	NET_CONNECTED :7
���� :state ״ֵ̬
notice: �ɸ��ݵ�ǰת̬���к���Ĳ���
******************************************************/
int opencpu_mqttstat();

/*****************************************************
����topic:
topic : ���ĵ�topic����
qos:  (0-2)
user_recvpubcb: �����ͻ���ɵĻص�����,������յ�������Ϣ����ʹ��ʱ����NULL
���� :���óɹ�����0������ʧ�ܷ�������ֵ��
notice: ����CONNNECTED ״̬ʱ���Է���
******************************************************/
int opencpu_mqttsub(char *topic, uint32_t qos, void(*user_recvpubcb));

/*****************************************************
ȡ������topic:
topic : ȡ�����ĵ�topic����
���� :���óɹ�����0������ʧ�ܷ�������ֵ��
notice: notice: ����CONNNECTED ״̬ʱ���Է���
******************************************************/
int opencpu_mqttunsub(char *topic, uint32_t qos);

/*****************************************************
������Ϣ:
topic: topic����
qos:  (0-2) 
retain: (0-1)
dup: 	(0-1)
msg_len: 0: ���ַ�����ʽ���ͣ���0 :��hex��ʽ���ͣ�ע�ⷢ�ͳ�����msg��Ӧ
msg: �����͵���Ϣ��
user_ackcb: �����ͻ���ɵĻص�������������Ϣ�յ�ack��ᴥ���ú���,��ʹ��ʱ����NULL
���� :����ɹ�����0��ʧ�ܷ�������ֵ��
notice: ����CONNNECTED ״̬ʱ���Է���
******************************************************/
int opencpu_mqttpub(char *topic, uint32_t qos, uint32_t retain, uint32_t dup, uint32_t msg_len, char *msg, void(*user_ackcb));

/*****************************************************
�Ͽ�����:
���� :�ɹ�����0��
notice: ����CONNNECTED ״̬ʱ���Խ��жϿ��������Ͽ��ɹ����ΪDISCONNECTED״̬
******************************************************/
int opencpu_mqttdisc();

/*****************************************************
�ͷ���Դ:
���� :�ɹ�����0��
notice: ����CONNNECTED ״̬ʱ���Խ��жϿ�����
******************************************************/
int opencpu_mqttdel();


/******************************************************
�����ǻص������ı�д˵��: �����첽�������ݣ�Ŀǰ�������ֻص�����:
1: publish ack �Ļص�����: ����qos>1��������Ϣ���յ�ack��ᴥ����
���͵Ļص��������û��ɸ����Լ�����Ҫ��ÿһ�����Ͱ���д����Ļص�������
����һ�α�д���ɵĻص�������������ַ����opencpu_mqttpub �����һ������
���ɡ�����
void opencpu_recvpuback_cb()
{
	opencpu_printf("OC get excepted ack\n");
}
/*********************************************************************
 2�����յ�ĳһtopic������Ϣ�Ļص���������һ��Ĭ�ϵĻص��������û��ɷ���
 �ú���(opencpu_defaultpublish_cb)��д��������Ļص�����,
/******************************************************************
opencpu_defaultpublish_cb : Ĭ�ϵ�һ���첽�ص����������յ��������·�������ʱ�ᴥ���ú�����
dup: 0 ���ظ�����1���ظ��� 
qos:  (0-2) 
retain: (0-1)
topicname: topic����
msgid:�������·��İ����
msg_len: ���յ������ݳ��� 
msg: �������·�������
notice: �ͻ��ڶ�������(opencpu_mqttsub)ʱ�������һ������ΪNULLʱ��
�յ�����Ĭ�ϵ��øú��������û����ĳtopic���Լ��Ĵ����ο��ú���
����д�µĻص���������opencpu_mqttsub���ɡ�
/*****************************************************/
void opencpu_defaultpublish_cb(uint32_t dup, uint32_t qos, uint32_t retained, uint32_t msgid, char *topicname, uint32_t msglen, char *msg);




#endif
