[Top]
components : router1 router2 router3
out : out1 out2 out3
in : in1 in2 in3
Link : in1 in@router1
Link : in2 in@router2
Link : in3 in@router3
Link : sal1@router1 out1
Link : sal2@router2 out2
Link : sal3@router3 out3
Link : sal2@router1 in@router2
Link : sal3@router1 in@router3
Link : sal1@router2 in@router1
Link : sal3@router2 in@router3
Link : sal1@router3 in@router1
Link : sal2@router3 in@router2

[router1]
components : queue1@Queue cola11@cola_sal cola12@cola_sal cola13@cola_sal ruteo1@ruteo_ip
out : sal1 sal2 sal3
in : in
Link : in in@queue1
Link : out@queue1 in@ruteo1
Link : out1@ruteo1 in@cola11
Link : out2@ruteo1 in@cola12
Link : out3@ruteo1 in@cola13
Link : out1@ruteo1 done@queue1
Link : out2@ruteo1 done@queue1
Link : out3@ruteo1 done@queue1
Link : out@cola11 sal1
Link : out@cola12 sal2
Link : out@cola13 sal3

[router2]
components : queue2@Queue cola21@cola_sal cola22@cola_sal cola23@cola_sal ruteo2@ruteo_ip
out : sal1 sal2 sal3
in : in
Link : in in@queue2
Link : out@queue2 in@ruteo2
Link : out1@ruteo2 in@cola21
Link : out2@ruteo2 in@cola22
Link : out3@ruteo2 in@cola23
Link : out1@ruteo2 done@queue2
Link : out2@ruteo2 done@queue2
Link : out3@ruteo2 done@queue2
Link : out@cola21 sal1
Link : out@cola22 sal2
Link : out@cola23 sal3

[router3]
components : queue3@Queue cola31@cola_sal cola32@cola_sal cola33@cola_sal ruteo3@ruteo_ip
out : sal1 sal2 sal3
in : in
Link : in in@queue3
Link : out@queue3 in@ruteo3
Link : out1@ruteo3 in@cola31
Link : out2@ruteo3 in@cola32
Link : out3@ruteo3 in@cola33
Link : out1@ruteo3 done@queue3
Link : out2@ruteo3 done@queue3
Link : out3@ruteo3 done@queue3
Link : out@cola31 sal1
Link : out@cola32 sal2
Link : out@cola33 sal3

[queue1]
preparation : 00:00:00:050

[queue2]
preparation : 00:00:00:050

[queue3]
preparation : 00:00:00:050

[cola11]
preparation : 00:00:00:050

[cola12]
preparation : 00:00:00:050

[cola13]
preparation : 00:00:00:050

[cola21]
preparation : 00:00:00:050

[cola22]
preparation : 00:00:00:050

[cola23]
preparation : 00:00:00:050

[cola31]
preparation : 00:00:00:050

[cola32]
preparation : 00:00:00:050

[cola33]
preparation : 00:00:00:050
