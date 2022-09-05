const firstName = document.getElementById("firstname");
const lastName = document.getElementById("lastname");
const email = document.getElementById("mail");
const userid = document.getElementById("userid");
const usercolor = document.getElementById("color")
const printForm = document.getElementById("user");
const display = document.getElementById("form-result");

const handlePrint = (e) => { // e는 event의 약자
    e.preventDefault(); // 창이 이동하는 것을 막아줌
    const fn = firstName.value;
    const ln = lastName.value;
    const em = email.value;
    const id = userid.value;
    const cl = usercolor.value;
    const diplaySpan = display.querySelector("span"); // id가 form-result인 태그 내부의 span 태그 선택

    diplaySpan.innerHTML = `
        Your First Name is ${fn}<br>
        Your Last Name is ${ln}<br>
        Your E-mail is ${em}<br>
        Your ID is ${id}<br>
        Your favorite color is ${cl} (HEX code)
    `;
};

// submit이 발생했을 때, handlePrint 함수를 실행
printForm.addEventListener("submit", handlePrint);