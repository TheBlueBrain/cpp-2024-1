# cpp-2024-1
Sukurti universiteto registrą.
Registras saugos universiteto informaciją (dabar gali saugoti tik informaciją apie žmones) ir registracijos momentą (kada buvo informacija įvesta į sistemą).

Vėliau duomenys bus saugomi viename objekte, kurio turinį būtų galima išsaugoti failę ir iš kurio būtų galima atkurti registrą.

Iskilo problemu su MIF Gitlab, todel projekto kopija, kuri bus pagrindine atnaujinant yra [cia](https://github.com/TheBlueBrain/cpp-2024-1)
I MIF gitlab bus atnaujinami duomenys, kuomet busiu fakultete, nes nepavyksta ikelti saugyklos neprisijungus prie fakulteto interneto, net nauojus VU VPN

Žmonių duomenų įršai gali būti srautais rašomi bei skaitomi iš failų. Taip pat gaalima vykdymo metu pakeisti ką daro "print" funkcija. Tam kad tai padaryti,
reikia viešą lauką prt pakeisti klasės objektu, kuris įgyvendina "interface"'ą Personprint. Iškviečiant print funkcija yra iskvieciama klasėje esantčio Persionprint* objekto print.

Serializacija, vykdoma binariniais srautais.
