```ui
// =========================
// DEATH SAVES
// =========================

reset(false)
success_1(false)
success_2(false)
success_3(false)

failure_1(false)
failure_2(false)
failure_3(false)

text("[color=#88FF88]Successes ✅[/color]") checkbox(success_1, "1") checkbox(success_2, "2") checkbox(success_3, "3")button("Clear", 50,reset=true)
text("[color=#FF6666]Failures     💀[/color]") checkbox(failure_1, "1") checkbox(failure_2, "2") checkbox(failure_3, "3")

if(success_1 && success_2 && success_3) {
  text("[color=#88FF88]STABLE[/color]")
}

if(failure_1 && failure_2 && failure_3) {
  text("[color=#FF0000]DEAD[/color]")
}
if(reset){
success_1=false
success_2=false
success_3=false
failure_1=false
failure_2=false
failure_3=false
reset=false
}
```