/*
 * Ceci est une ardoise JavaScript.
 *
 * Saisissez du code JavaScript, puis faites un clic droit ou sélectionnez à partir du menu Exécuter :
 * 1. Exécuter pour évaluer le texte sélectionné (Cmd-R),
 * 2. Examiner pour mettre en place un objet Inspector sur le résultat (Cmd-I), ou,
 * 3. Afficher pour insérer le résultat dans un commentaire après la sélection. (Cmd-L)
 */


function  openEvent()
{
  eventListe = document.body.children[4].children[1].children[0].children[2].children[0].children[0].children[0].children[1];
  examButton = eventListe.children[1].children[0].children[2].children[2].children[0];
  examButton.click();
  waitEvent();
}

function  waitEvent()
{
  setTimeout(function(){
    if (document.body.children[5].children[0].children[0].children[1].children[1] === undefined)
      waitEvent();
    else
      checkEvent();
  }, 50);
}

function  checkEvent()
{
  setTimeout(function(){
    eventUsers = document.body.children[5].children[0].children[0].children[1].children[1].children[3].children[1];
    if (eventUsers.innerText === "250 / 250")
    {
      document.body.children[5].children[0].children[0].children[2].children[0].click();
    }
    else
    {
      console.log("Empty");
      document.body.children[5].children[0].children[0].children[2].children[1].click();
      window.clearInterval(BRUTE);
    }
  }, 1000);
}

BRUTE = setInterval(function(){
  openEvent();
}, 2000);