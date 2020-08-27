var planted = [2];
var imageArr = ["tree.svg"];

window.addEventListener("load", function() {
    
    const form = document.getElementById("inputs");
    document.getElementById("print_trees").innerHTML = "";
    imageArr.forEach(loadImages); 

    form.addEventListener("submit", (event) => {
        event.preventDefault();

        planted.shift();
        imageArr.shift();

        var k = document.getElementById("for_k").value;
        var m = document.getElementById("for_m").value;
        var v = 2;

        for (var toBeCutted = 0; toBeCutted < k; toBeCutted++) {
            
            if(planted.length != 0) {
                v = planted.shift();
            }
            for(var toBePlanted = 0; toBePlanted < (v+1)%m; toBePlanted++) {
                planted.push(toBePlanted);
            }
        }

        console.log(planted);

        for (var i = 0; i < planted.length; i++) {
            imageArr.push("tree.svg");
        }

        
        document.getElementById("print_trees").innerHTML = "";
        imageArr.forEach(loadImages); 

    });
});

function loadImages(images, index) {
    document.getElementById("print_trees").innerHTML += `
        <div style="border-style: solid; border-width: 2px; padding: 5px; margin-left: 2.5px; margin-right: 2.5px">
            <p>${planted[index]}</p>
            <img src="${images}" width="100px">
        </div>
    `;
}