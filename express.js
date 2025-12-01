// const express = require("express");
// const path = require("path");
// const app = express();

// app.use(express.json());
// app.use(express.static("public"));

// app.get("/", (req, res) => {
//     res.sendFile(path.resolve(__dirname, "index.html"));
// });

// app.get("/test", (req, res) => {
//     console.log("Testing page...");
//     res.send({ message: "Testing Page" });
// });

// app.post("/greet", (req, res) => {
//     console.log("Received body:", req.body);

//     const { name } = req.body;
//     if (!name) {
//         return res.status(400).json({ error: "Name is required" });
//     }

//     return res.json({ message: Hello World ${name} });
// });

// app.listen(3000, () => {
//     console.log("Server is running on http://localhost:3000");
// });





// express.js

// 1. Install required packages: npm i express mongoose dotenv
// 2. Import modules
const express = require('express');
const mongoose = require('mongoose');
// load environment variables
require('dotenv').config();

// Initialize Express app
const app = express();

// Middleware to parse JSON bodies
app.use(express.json());

// MongoDB Atlas connection
const MONGODB_URI = process.env.MONGODB_URI || 'mongodb://localhost:27017/myDatabase'; // Fallback to local
console.log('Connecting to MongoDB Atlas...');

// 3. Connect to MongoDB using Mongoose
mongoose.connect(MONGODB_URI, {
    serverSelectionTimeoutMS: 5000, // Timeout after 5s if selection fails
    socketTimeoutMS: 45000, // Close sockets after 45 seconds of inactivity
})
.then(() => {
    console.log('Connected to MongoDB Atlas successfully!');
})
.catch(err => {
    console.error('❌ MongoDB Connection Error:', err.message);
    console.error('💡 Make sure your MongoDB Atlas connection string is correct in .env file');
});

// User Schema
const userSchema = new mongoose.Schema({
    name: {
        type: String,
        required: [true, 'Name is required'],
        trim: true
    },
    email: {
        type: String,
        required: [true, 'Email is required'],
        trim: true,
        lowercase: true // store emails in lowercase
    },
    createdAt: {
        type: Date,
        default: Date.now // set a default date
    }
});

// Create User Model
const User = mongoose.model('User', userSchema);

// Routes

// GET / - Home page, serving an HTML file
app.get('/', (req, res) => {
    // Note: Assuming 'userinput.html' is in the root directory or configured path
    res.sendFile(__dirname + '/index.html');
});

// GET /about-us - Check database connection status
app.get('/about-us', (req, res) => {
    const isConnected = mongoose.connection.readyState === 1 ? 'connected' : 'disconnected';
    res.json({
        message: 'Hello world!',
        database: isConnected
    });
});

// POST /submit - Save user to MongoDB (Async route)
app.post('/submit', async (req, res) => {
    try {
        const { name, email } = req.body;

        // Basic validation
        if (!name || !email) {
            return res.status(400).json({
                error: 'Name and email are required'
            });
        }

        // Create and save user to mongoDB
        const newUser = new User({ name, email });
        const savedUser = await newUser.save();

        res.json({
            message: `Hello ${savedUser.name}! Your data has been saved to MongoDB.`,
            user: {
                id: savedUser._id,
                name: savedUser.name,
                email: savedUser.email,
                createdAt: savedUser.createdAt
            }
        });
    } catch (error) {
        console.error('Error saving user:', error);
        res.status(500).json({
            error: 'Failed to save user to database'
        });
    }
});

// GET /users - Get all users
app.get('/users', async (req, res) => {
    try {
        const users = await User.find().sort({createdAt: -1}); // Exclude __v field
        res.json({
            count: users.length,
            users: users
        });
    } catch (error) {
        console.error('Error fetching users:', error);
        res.status(500).json({
            error: 'failed to fetch users',
            message: error.message
        });
    }
});

// GET /users/:id - Get user by ID
app.get('/users/:id', async (req, res) => {
    try {
        const userId = req.params.id;
        const user = await User.findById(userId).select('-__v'); // Exclude __v field

        if (!user) {
            return res.status(404).json({
                error: 'User not found'
            });
        }

        res.json({
            user: user
        });
    } catch (error) {
        console.error('Error fetching user by ID:', error);
        res.status(500).json({
            error: 'failed to fetch user',
            message: error.message
        });
    }
});

// POST /api/greet - New API endpoint that takes name and returns with Hello world
app.post('/api/greet', async (req, res) => {
    try {
        const { name } = req.body;

        if (!name) {
            return res.status(400).json({
                error: 'Name is required'
            });
        }

        // optionally save to database
        const userEmail = `${name.toLowerCase().replace(' ', '.')}@example.com`;
        const newUser = new User({ name, email: userEmail });
        await newUser.save();

        res.json({
            message: `Hello world! ${name}`,
            saved: true,
            userId: newUser._id
        });
    } catch (error) {
        console.error('Error in /api/greet:', error);
        res.status(500).json({
            error: 'Failed to process request',
            message: error.message
        });
    }
});


// Start server
const PORT = process.env.PORT || 3000;

app.listen(PORT, () => {
    console.log(`✅ Server is running on port ${PORT}`);
    console.log('Available endpoints:');
    console.log('GET /                      - Home page');
    console.log('GET /about-us              - About page');
    console.log('POST /submit               - Submit user (name, email)');
    console.log('GET /users                 - Get all users');
    console.log('GET /users/:id             - Get user by ID');
    console.log('POST /api/greet            - greet API');
});