#include "clcd.hpp"
//#include "../../circuit/F405ControlBoard.hpp"
#include "../../../circuit/function/delay.hpp"

//TODO: 関数の説明メモ書き修正

#define LCD_RS_CMD  0   //RS端子:コマンド
#define LCD_RS_DATA 0   //RS端子:データ

CharacterLcd::~CharacterLcd()
{
    delete m_rs;
    delete m_e;
    delete m_db4;
    delete m_db5;
    delete m_db6;
    delete m_db7;
}

void CharacterLcd::setup(GPIO* rs, GPIO* e, GPIO* db4, GPIO* db5, GPIO* db6, GPIO* db7)
{
    m_rs = rs;
    m_e = e;
    m_db4 = db4;
    m_db5 = db5;
    m_db6 = db6;
    m_db7 = db7;

    delay_ms(20);
    pinOut(0x3, LCD_RS_CMD);            // 8bit mode set
    delay_ms(5);
    pinOut(0x3, LCD_RS_CMD);            // 8bit mode set
    delay_ms(1);
    pinOut(0x3, LCD_RS_CMD);            // 8bit mode set
    delay_ms(1);
    pinOut(0x2, LCD_RS_CMD);            // 4bit mode set

    command(0x28);
    //command(0x0E);    //カーソルON
    command(0x0C);        //カーソルOFF
    command(0x06);
    command(0x01);
}

/*
 * function: DATA信号ピン設定
 * brief: 引数通りに4ビットデータを出力する
 * arguments: 4ビットデータ
 * return: void
 */
void CharacterLcd::pinOut(uint8_t data)
{
    //LCD_DB4 = data&0x01;            /*dataに代入された数値通りに各ピンから出力する*/
    m_db4->write(data&0x01);
    data>>=1;
    //LCD_DB5 = data&0x01;
    m_db5->write(data&0x01);
    data>>=1;
    //LCD_DB6 = data&0x01;
    m_db6->write(data&0x01);
    data>>=1;
    //LCD_DB7 = data&0x01;
    m_db7->write(data&0x01);
}

/*
 * function: コード送信
 * brief: 4ビットのコマンド又はデータを送信
 * arguments: 4ビットコマンド（データ）、RS端子
 * return: void
 */
void CharacterLcd::pinOut(uint8_t code, int rsmode)
{
    //LCD_E = 0;
    m_e->write(0);
    pinOut(code);                /*DATA信号出力*/
    //LCD_RS = rsmode;                //0: コマンド、1: データ
    m_rs->write(rsmode);

    //LCD_E = 1;            /*E信号Hレベル*/
    m_e->write(1);
    delay_us(2);
    //LCD_E = 0;            /*E信号Lレベル*/
    m_e->write(0);
    delay_us(2);
}

/*
 * function: データ送信
 * brief: 1バイトデータを送信する
 * arguments: 1バイトデータ
 * return: void
 */
void CharacterLcd::dataOut(uint8_t ascii)
{
    pinOut(ascii>>4, LCD_RS_DATA);        /*上位4ビット出力*/
    pinOut(ascii, LCD_RS_DATA);            /*下位4ビット出力*/
    delay_us(50);                        /*1文字表示処理は37us待機*/
}

/*
 * function: コマンド送信
 * brief: 1バイトコマンドを送信する
 * arguments: 1バイトコマンド
 * return: void
 */
void CharacterLcd::command(uint8_t cmd)
{
    pinOut(cmd>>4, LCD_RS_CMD);            /*上位4ビット出力*/
    pinOut(cmd, LCD_RS_CMD);            /*下位4ビット出力*/
    //コマンドがClear Display (0x01)またはReturn Home (0x02 or 0x03)のとき
    if(cmd>>2 == 0) delay_ms(2);
    else delay_us(37);
}

/*
 * function: 文字列送信
 * brief: LCDに文字列データを送信
 * arguments: 文字列
 * return: void
 */
void CharacterLcd::strOut(const uint8_t *str)
{
    const uint8_t *p = str;
    while(*p)
    {
        dataOut(*p);
        p++;
    }
}

//各行先頭のアドレス
const uint8_t CharacterLcd::m_LineHeadAddress[2] = {0x00, 0x40};
//1行の表示文字数
const uint8_t CharacterLcd::m_ColumnNumber = 16;

/*
 * function: カーソル位置指定
 * brief: カーソル位置を指定する。x,y共に0から始める
 * arguments: x（横）、y（縦）
 * return: void
 */
void CharacterLcd::cursor(int x, int y)
{
    command(0x80 | (m_LineHeadAddress[y] + x));
}

/*
 * function: 指定行全消去&指定行の先頭にカーソル設定
 * brief: 特定の行をまっさらな状態から書き込む時に使用
 * arguments: 行（縦、0から始める）
 * return: void
 */
void CharacterLcd::line(int y)
{
    command(0x80 | m_LineHeadAddress[y]);
    for(int i = 0; i < m_ColumnNumber; i++)
    {
        this->strOut((const unsigned char*)" ");
    }
    command(0x80 | m_LineHeadAddress[y]);
}

/*
 * function: 画面全消去
 * brief: 画面を全消去し、カーソルを先頭行先頭に設定
 * arguments: void
 * return: void
 */
void CharacterLcd::clear(void)
{
    command(0x01);            //Clear Display
}

/*
 * function: 書式付き文字列表示
 * brief: LCDに文字列を表示させる。改行は使用不能なので、cursor関数などを使う。
 * arguments: printfと同様
 * return: printfと同様
 */
int CharacterLcd::printf(const char* format, ...)
{
    char buffer[40];
    va_list ap;
    int len;
    va_start(ap, format);
    len = vsprintf(buffer, format, ap);
    va_end(ap);
    strOut((const uint8_t*)buffer);
    return len;
}
