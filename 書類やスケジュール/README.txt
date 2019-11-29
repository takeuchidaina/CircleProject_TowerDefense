【環境構築について】
記入者：竹内　大奈
記入日：2019/06/30

〇作業環境
VisualStudioComunity2019

〇使用ライブラリ
Dxライブラリ

〇使用ツール
・Slack
・Trello
・SourceTree
・Github
・スプレッドシート

〇各ツール管理者
　Slack：高井
　Git：takeuchidaina(アカウント名)
　Trello：高井
　スプレッドシート：石倉



ーーーーーーーーーーーーーー手順ーーーーーーーーーーーーーー
1.https://dxlib.xsrv.jp/use/dxuse_vscom2019.html
　上記のURLを元にプロジェクトを作成
　
　※プロジェクト作成ー手順5の
　　ソリューションとプロジェクトを同じディレクトリに配置するにチェックは
　　行わずチェックを外した状態で作成
　　意図：ファイルがまとまるため、これによってバグが出た場合は変更

　プロジェクト名はファイルパスを相対パスで記入するため何でもよい

2.プロジェクト名.slnファイルがある場所に「resorce」ファイルを作成

3.resorceファイルにSourceTreeよりクローン
　URL：https://github.com/takeuchidaina/CircleProject_TowerDefense
　保存先はresorceまでのファイルパス
　名前は自由にわかりやすいもの

4.GitFlowを有効化