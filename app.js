// const express = require('express');
// const app = express();

// app.get('/', (req, res) => {
   
//    // res.send('Hello World');
//    res.sendFile(__dirname + '/index.html');
//    console.log(__dirname);
// });

//     app.get("/test",(req,res){
//         res.send("Testing page");
//     });
// app.listen(3000, () => {
//     console.log('Server is running on http://localhost:3000');
// });



// express.js (Corrected version)

const express = require('express');
const app = express();

app.get('/', (req, res) => {
    // This route serves your index.html file
    res.sendFile(__dirname + '/index.html');
    console.log(__dirname);
});

// FIXED: Added the missing closing parenthesis ")" before the function body
app.get("/test", (req, res) => {
    res.send("Testing page");
});

app.listen(3000, () => {
    console.log('Server is running on http://localhost:3000');
});