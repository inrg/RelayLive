#pragma once

struct lws;
struct lws_ring;

namespace HttpWsServer
{
    class CLiveWorker;

    enum MediaType
    {
        media_error = 0,
        media_flv,
        media_hls,
        media_h264,
        media_mp4
    };

    /** per session structure */
    struct pss_http_ws_live {
        pss_http_ws_live      *pss_next;
        struct lws            *wsi;              //http/ws ����
        MediaType             media_type;        //��ǰ���������ý���ʽ����
        bool                  isWs;              //false��http����true��websocket
        bool                  m_bSendHead;       //��ǰ�����Ѿ����͵Ĳ���
        char                  path[128];         //���Ŷ������ַ
        char                  clientName[50];    //���Ŷ˵�����
        char                  clientIP[50];      //���Ŷ˵�ip
        char                  strErrInfo[128];   //���ܲ���ʱ�Ĵ�����Ϣ
        CLiveWorker           *m_pWorker;        //CFlvWorker����
        struct lws_ring       *ring;             //�������ݻ�����
        uint32_t              tail;              //ringbuff�е�λ��
        bool                  culled;
    };
    extern int callback_live_http(struct lws *wsi, enum lws_callback_reasons reason, void *user, void *in, size_t len);
    extern int callback_live_ws(struct lws *wsi, enum lws_callback_reasons reason, void *user, void *in, size_t len);
};