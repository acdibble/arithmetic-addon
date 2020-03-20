const { expect } = require('chai');
const Arithmetic = require('.');

describe('Arithmetic', () => {
  let arithmetic;

  beforeEach(() => {
    arithmetic = new Arithmetic();
  });

  describe('getTotal', () => {
    it('returns total without any operations having been performed', () => {
      expect(arithmetic.getTotal()).to.eql(0);
    });
  });

  describe('add', () => {
    it('adds to the total', () => {
      arithmetic.add(10);
      expect(arithmetic.getTotal()).to.eql(10);
    });
  });

  describe('sub', () => {
    it('subtracts from the total', () => {
      arithmetic.sub(10);
      expect(arithmetic.getTotal()).to.eql(-10);
    });
  });

  describe('mul', () => {
    it('multiplies the total', () => {
      arithmetic.add(1);
      arithmetic.mul(10);
      expect(arithmetic.getTotal()).to.eql(10);
    });
  });

  describe('div', () => {
    it('divides the total', () => {
      arithmetic.add(10);
      arithmetic.div(10);
      expect(arithmetic.getTotal()).to.eql(1);
    });

    it('throws an error on division by zero', () => {
      expect(() => arithmetic.div(0)).to.throw('Cannot divide by zero');
    });
  });
});
