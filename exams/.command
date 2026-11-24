vim $(for d in */; do echo $d/{SUBJECT.txt,*.c}; done)
