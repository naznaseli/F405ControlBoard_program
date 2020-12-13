ファイル構成
===
F405基板についてのファイル(今回の構成ではそれ以外の大会用ファイルの説明も追加、すなわちhowtouse)
基板についてのプログラムはそれだけでgitプロジェクトとしてまとめる(バージョン管理)
→それをライブラリ(gitsubmodule)もしくは各バージョンをダウンロードしてとして大会プロジェクトで使う
```
F405ControlBoard_program
    ├ .settings
    ├ Drivers/                   F405ドライバ
    ├ src/
0   │   ├ hardware/              ハードの低レイヤ部分
0   │   │   ├ communication/    通信関連
0   │   │   ├ function/         回路班便利機能
0   │   │   ├ parts/            アクチュエータ、センサ、通信or実基板操作のインタフェース(peripheralの一個上のレイヤ、制御班とのインタフェース)
0   │   │   │   ├ actuator/    アクチュエータ
0   │   │   │   ├ circuit/     LED、ボタン、ユーザエンコーダ、LCD、TFT
0   │   │   │   └ sensor/      センサ
0   │   │   └ peripheral/       一番低レイヤの部分
0   │   │   │   ├ RCC.cpp/hpp
0   │   │   │   ├ GPIO.cpp/hpp
0   │   │   │   ├ TIM.cpp/hpp
0   │   │   │   ├ IWDG.cpp/hpp
0   │   │   │   ├ USART.cpp/hpp
0   │   │   │   ├ bxCAN.cpp/hpp
    │   ├ software/             制御関連(制御汎用ライブラリみたいな)、ハードに依存しない
    │   │   ├ function/         制御用便利機能
    │   │   │   ├ deadreackoning.cpp/hpp
    │   │   │   ├ ff.cpp/hpp
    │   │   │   ├ filter.cpp/hpp
    │   │   │   ├ odometri.cpp/hpp
    │   │   │   ├ 
    │   │   │   ├ 
    │   │   ├ dead_reckoning.cpp/hpp
    │   │   ├ odometri.cpp/hpp
    │   │   ├
    │   │   └ 
    │   ├ Tourobo2016/  とうロボに関するファイル、フィールド、マシン、各ファイルや低レイヤ定義に依存して問題なし
    │   │   ├ actuator.cpp/hpp
    │   │   ├ command.cpp/hpp
    │   │   ├ control.cpp/hpp
    │   │   ├ machine.cpp/hpp       実マシン関連
    │   │   ├ sensor.cpp/hpp
    │   │   ├
    │   │   └ 
0   │   ├ main.cpp
0   │   ├ syscalls.c
0   │   └ system.c
    ├ Startup/
    │   ├
    │   ├
    │   ├
    │   └ 
    ├ .cproject
    ├ .gitignore
    ├ .project
    ├ Makefile
    ├ MEMO.md
    ├ README.md
    ├ STM32F405RGTX_FLASH.ld
    ├ STM32F405RGTX_RAM.ld
    │
    │
    │
    │

```