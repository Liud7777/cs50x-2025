from flask import Flask, request, render_template_string, jsonify
import sqlite3
import hashlib
import os

app = Flask(__name__)

# Fixed: Use environment variable for secret key with fallback for development
app.secret_key = os.environ.get('SECRET_KEY') or os.urandom(24)

# Fixed: Use parameterized queries to prevent SQL injection
def get_user(username):
    conn = sqlite3.connect('users.db')
    cursor = conn.cursor()
    # Use parameterized query to prevent SQL injection
    query = "SELECT * FROM users WHERE username = ?"
    cursor.execute(query, (username,))
    result = cursor.fetchone()
    conn.close()
    return result

# Fixed: Corrected infinite loop and improved password validation
def validate_password(password):
    special_chars = "!@#$%^&*"
    has_special = False
    i = 0
    while i < len(password) and not has_special:
        if password[i] in special_chars:
            has_special = True
        # Fixed: increment i to prevent infinite loop
        i += 1
    return has_special and len(password) >= 8

@app.route('/')
def home():
    return render_template_string('''
    <h1>User Management System</h1>
    <form action="/login" method="post">
        Username: <input type="text" name="username"><br>
        Password: <input type="password" name="password"><br>
        <input type="submit" value="Login">
    </form>
    ''')

@app.route('/login', methods=['POST'])
def login():
    username = request.form['username']
    password = request.form['password']
    
    if not validate_password(password):
        return "Password must be at least 8 characters with special characters"
    
    user = get_user(username)
    if user:
        return f"Welcome {user[1]}!"
    else:
        return "User not found"

@app.route('/search')
def search():
    query = request.args.get('q', '')
    # Bug 4: XSS vulnerability (bonus bug)
    return f"<h1>Search Results for: {query}</h1>"

if __name__ == '__main__':
    # Initialize database
    conn = sqlite3.connect('users.db')
    cursor = conn.cursor()
    cursor.execute('''
        CREATE TABLE IF NOT EXISTS users (
            id INTEGER PRIMARY KEY,
            username TEXT,
            password TEXT
        )
    ''')
    cursor.execute("INSERT OR IGNORE INTO users (username, password) VALUES ('admin', 'password123!')")
    cursor.execute("INSERT OR IGNORE INTO users (username, password) VALUES ('user', 'mypass456@')")
    conn.commit()
    conn.close()
    
    app.run(debug=True)