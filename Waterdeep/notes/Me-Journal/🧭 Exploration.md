```mermaid
kanban
  a[🔍 To Investigate]
  a[📝 Available]
    c2[Somni]: Un somni misterios amb una ciutat i una criatura terrorifica.
      Possiblament al Undermountain ja que era un lloc tancat.
      Li explico lo del somni a Xoblob i quan ho sent no ho vol ni sentir. Em fa mig fora de la botiga.

    a1[Tresor de Neverenguer]: Ajudarem al fill Neverenguer a trobar el tresor si existeix.
      Ens dóna entrades per anar a la Opera amb en Mirth.
      Clarament el penjoll tenia alguna pista de tot plegat.

    a3[Acabar amb el "nous" Zhentarim]: Daril
      No ens demana res però deixa clar que no s'hi porta bé.

    a8[Daril contactarà amb nosaltres]: Es per quedar amb un dels seus que té una info.
    a9[Matar un buscat pels Lords]: No cobrarem
    a11[Busca info del culte de Asmodeus]: Van està espiant un pis que és del Xanathar.
      Hi havia un mapa també amb la cripta marcada.
      I la cultista ens va dir que havien descobert la cripta.

    a12[Mhir ens fa anar a parlar amb un]: Ens fa anar a parlar amb un, ens dona una direcció i diu que li expliquem el què ha passat.
      És un contacte dels Arpistes.

    a13[Mans Grises / Força Gris]: Objectiu pendent d'en Nim: entendre si podria arribar a formar part d'aquesta força d'elit de Waterdeep.
      Ser seleccionat per la Bara Negra voldria dir que la ciutat no només el tolera, sinó que l'accepta com algú capaç de protegir-la.

    a14[Skimo, amic d'en Davil]: Diu que necessita que portem un beuratge d'un lloc a un altre.
    a15[Cara trencada]: Sabem on viu, a per ell!
  a[⚔ In Progress]
    c1[Necklace]: Fill the necklace with charms related to my 7 lifes
    a1[Undermountain]: Necessitem diners o més poder per anar al undermountain.
      Xoblob diu que busqui mercenaris, aventurers o Xanathar per treure artefactes i info de la zona.
      Però sobretot que no baixi

    a4[Obrir una taverna]
  a[✅ Completed]
    c1[Bolo]: Ha perdut un amic pels carrers de la ciutat amb la violencia que hi ha últimament pels carrers de prop del port.
      500 Dracs per trobar el seu amic. (50 per avançat)
      Al final en dóna una mansió en comptes de l'or.

    a1[Escriptor]: Vol veurens a la taverna.
      Treballa pels nobles i ens dóna feines.

    a2[Salvar llibreria]: Mhir ens demana que salvem una anciana que té una llibreria i l'ha atac un monstre.
      Salvem el seu gat i ens dóna:
      pergamins x4
      miniventilador

    a3[Recistes d'elf]: Estan matant elfs per la ciutat. Vol que acabem amb això.
      25 d'or.
      A més a més sabem que els troben decapitats.
      Han matat sobretot al port a mariners i acostumen anar a la taverna Blumermaid.
      És una taverna que porten elfs així que molts van allà.
      El que saben és que les 3 victimes anaven allà.
      Hem matat el Drow que matava a elf.
      En Gaudenci està molt espentat així que no direm res de qui era
      Daril ens paga generosament i diu que està molt content amb nosaltres. Gaudenci diu que no podem di kies

    a4[Espanta Ocells que ataquen granges]: La Enclave Esmeralda ens damana ajuda per acabar amb aquest atac maligne de les granges
    a5[Find anchor team]: Hauria de trobar alguna cosa que ens uneixi a tots.
      Fer alguna cosa perquè tots vagin més o menys a una.
      Feia molt que no podia està tant temps amb unes mateixes persones sense haver de fugir.
      Haig de lluitar per la unitat.
      La Taverna ens ha unit

    a6[Portar una notícia a un Editorial]: Si no ens maten
    a7[Hermia al turó de Waterdeep (Halam)]: Anant en compte amb les paraules i demanar-li sobre la amenaça que està patint la ciutat.
      ---
      > El bessó de les ombres s'amaga sota un rostre aliè. Empenyent peos mentre ell romana en silenci.
      > No és l'únic monstre en aquest tauler però és l'únic que camina sense deixar petjada fins que colpeja.

  a[❌ Failed]
    a1[Carrer maritim (Blau)]: Dieun que hi ha alguna cosa màgica estranya i blava al carrer marítim, al nort de la ciutat.
      La zona alta. La van fer sense mi. No en ser res.

    a2[Protegir el Gremi d'escrombriaires.]: El gremi dels escombriaries tenen problemes quan intenten fer la seva feina amb lo moguda que està la ciutat.
      Diu que necessita que els escoltem. Que els protegim.
      Recompensa 4 d'or.
      Fail: Jalaster fill de puta. A ningú li cau bé

```


```ui
enum(selected_map, "🗺 Select", 220, ["Faerun", "Waterdeep"])

if(starts_with(selected_map, "Faerun")){ map(faerun_map, 500, 500) }
if(starts_with(selected_map, "Waterdeep")){ map(waterdeep_map, 500, 500) }
```